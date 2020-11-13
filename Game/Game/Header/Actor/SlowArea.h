#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"
class SlowArea :
	public GameObject
{
private:
	Timer deadTimer;//�����鎞��
public:
	SlowArea(Vector2 *position);
	~SlowArea();
	//������
	void Initialize()override;
	//���t���[������
	void Update()override;
	//�`�揈��
	void Draw()override;
	//�q�b�g������
	void Hit(GameObject *obj)override;
};

