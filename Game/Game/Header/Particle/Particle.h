#pragma once
#include "Vector2.h"


//�p�[�e�B�N���̐e�N���X
class Particle
{
protected:
	Vector2* position;//���W
	Vector2* velocity;//�ړ���
	int hp,maxhp;//���݂�hp,�ő��hp
	float scale,maxscale,addScale;//���݂̑傫���A�ő�̑傫���A�傫���Ȃ�䗦
	bool isDead;//���S�^�U
public:
	Particle(Vector2* position,int maxhp, float scale);
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

