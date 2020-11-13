#pragma once
#include "Vector2.h"
#include "Timer.h"

//�p�[�e�B�N���̐e�N���X
class Particle
{
protected:
	Vector2* position;//���W
	Vector2* velocity;//�ړ���
	int hp,maxhp;//���݂�hp,�ő��hp
	float scale,maxscale,addScale;//���݂̑傫���A�ő�̑傫���A�傫���Ȃ�䗦
	Timer deadTimer;
	bool isDead;//���S�^�U
public:
	Particle(Vector2* position);
	~Particle();
	//���S�^�U
	bool IsDead();
	//����������
	virtual void Initialize();
	//���t���[������
	virtual void Update();
	//�`�揈��
	virtual void Draw();
};

