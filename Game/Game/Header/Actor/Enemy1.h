#pragma once
#include "Enemy.h"
#include "Vector2.h"

class Enemy1 :
	public Enemy
{
private:

public:
	Enemy1(Vector2 *position,int hp);
	~Enemy1();
	//������
	void Initialize()override;
	//���t���[������
	void Update()override;
	//�`�揈��
	void Draw()override;
	//�q�b�g������
	void Hit(GameObject *obj)override;
};

