#pragma once
#include "Enemy.h"
#include "Vector2.h"

class Enemy3 :
	public Enemy
{
public:
	Enemy3(Vector2 *position,int hp);
	~Enemy3();
	//������
	void Initialize()override;
	//���t���[������
	void Update()override;
	//�`�揈��
	void Draw()override;
	//�q�b�g������
	void Hit(GameObject *obj)override;
};

