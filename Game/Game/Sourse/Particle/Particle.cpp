#include "Particle.h"
#include "ParticleManager.h"
#include "DxLib.h"

Particle::Particle(Vector2* position)
{
	this->position = new Vector2(position->x,position->y);
	delete position;
	velocity = new Vector2(0, 0);
	hp = GetRand(maxhp) + maxhp / 2;
	this->maxscale = maxscale;
	this->scale = 1;
	addScale = this->maxscale / this->hp;
	isDead = false;
	ParticleManager::Instance()->Add(this);
}


Particle::~Particle()
{
	delete position;
	position = nullptr;
	delete velocity;
	velocity = nullptr;
}

//���S�^�U
bool Particle::IsDead()
{
	return isDead;
}

//����������
void Particle::Initialize()
{
}

//���t���[������
void Particle::Update()
{
	position->x += velocity->x;
	position->y += velocity->y;
	hp--;
	scale += addScale;
	//hp���[�����Ⴂ�ꍇ����
	if (hp <= 0)
	{
		isDead = true;
	}
	//�ő�̑傫����茻�݂̑傫�����傫���ꍇ����
	if (scale >= maxscale)
	{
		isDead = true;
	}
}

//�`�揈��
void Particle::Draw()
{
}
