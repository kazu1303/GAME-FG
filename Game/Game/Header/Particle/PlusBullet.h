#pragma once
#include "Particle.h"
class PlusBullet :
	public Particle
{
public:
	PlusBullet(Vector2 *position);
	~PlusBullet();
	//����������
	virtual void Initialize();
	//���t���[������
	virtual void Update();
	//�`�揈��
	virtual void Draw();
};

