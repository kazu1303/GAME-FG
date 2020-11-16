#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"
class SlowBullet :
	public GameObject
{
private:
	Timer deadTimer;//�����鎞��
public:
	SlowBullet(Vector2 *position,float radian);
	~SlowBullet();
	//������
	void Initialize()override;
	//���t���[������
	void Update()override;
	//�`�揈��
	void Draw()override;
	//�q�b�g������
	void Hit(GameObject *obj)override;
};

