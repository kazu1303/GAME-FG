#pragma once
#include "GameObject.h"
#include "Vector2.h"

class PlayerBullet :
	public GameObject
{
public:
	PlayerBullet(Vector2 *position, float radian);
	~PlayerBullet();
	//������
	void Initialize()override;
	//���t���[������
	void Update()override;
	//�q�b�g������
	void Hit(GameObject* obj) override;
	//�`�揈��
	void Draw()override;
};

