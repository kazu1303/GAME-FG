#include "ParticleManager.h"
#include <memory>
#include <vector>
using namespace std;

vector<shared_ptr<Particle>> particles;//�p�[�e�B�N�����i�[
vector<shared_ptr<Particle>> addParticle;//�V�����p�[�e�B�N�����i�[

ParticleManager* ParticleManager::instance = nullptr;

ParticleManager::ParticleManager()
{
	instance = this;
	Initialize();
}


ParticleManager::~ParticleManager()
{
}

//�C���X�^���X
ParticleManager * ParticleManager::Instance()
{
	return instance;
}

//����������
void ParticleManager::Initialize()
{
	//vector�̒��g��S����
	particles.clear();
	addParticle.clear();
	particles.shrink_to_fit();
	addParticle.shrink_to_fit();
}

//���t���[������
void ParticleManager::Update()
{
	//�V�����������ꂽparticle��ǉ�
	copy(addParticle.begin(), addParticle.end(), back_inserter(particles));
	addParticle.clear();
	//�A�b�v�f�[�g
	for (auto itr : particles)
	{
		itr->Update();
	}
	//���S����
	for (auto itr = particles.begin(); itr != particles.end(); )
	{
		if ((*itr)->IsDead())
		{
			itr = particles.erase(itr);
		}
		else
		{
			itr++;
		}
	}
}

//�`�揈��
void ParticleManager::Draw()
{
	//�p�[�e�B�N���̕`��
	for (auto itr : particles)
	{
		itr->Draw();
	}
}

//�p�[�e�B�N����������
void ParticleManager::Add(Particle * particle)
{
	shared_ptr<Particle> addpart(particle);
	addParticle.push_back(addpart);
}
