#pragma once
#include "Particle.h"

class DeadParticle : public Particle
{
private:
	float speed;
public:
	DeadParticle(Vector2* position);
	~DeadParticle();
	//����������
	virtual void Initialize();
	//���t���[������
	virtual void Update();
	//�`�揈��
	virtual void Draw();
};
