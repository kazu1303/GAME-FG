#pragma once
#include "GameObject.h"
#include "Vector2.h"

class EnemyBullet :
	public GameObject
{
public:
	EnemyBullet(Vector2 *position);
	~EnemyBullet();
	//������
	void Initialize()override;
	//���t���[������
	void Update()override;
	//�`�揈��
	void Draw()override;
	//�q�b�g������
	void Hit(GameObject *obj)override;
};

