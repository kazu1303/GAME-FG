#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"
class PutBullet :
	public GameObject
{
private :
public:
	PutBullet(Vector2 *position, float radian);
	~PutBullet();
	//����������
	void Initialize()override;
	//���t���[������
	void Update()override;
	//�`�揈��
	void Draw()override;
	//�q�b�g������
	void Hit(GameObject *obj)override;
	//�_���[�W�v�Z
	void Damege(int attack)override;
};

