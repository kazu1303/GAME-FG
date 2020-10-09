#pragma once
#include "Particle.h"

class ParticleManager
{
private:
	static ParticleManager* instance;//�C���X�^���X
public:
	ParticleManager();
	~ParticleManager();
	//ParticleManager�̃C���X�^���X��Ԃ�
	static ParticleManager* Instance();
	//����������
	void Initialize();
	//���t���[������
	void Update();
	//�`�揈��
	void Draw();
	//���������p�[�e�B�N����������
	void Add(Particle* particle);
};

