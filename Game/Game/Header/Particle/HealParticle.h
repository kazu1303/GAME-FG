#pragma once
#include "Particle.h"
class HealParticle :
	public Particle
{
private:
	float range;
public:
	HealParticle(Vector2 *position,float range);
	~HealParticle();
	//����������
	virtual void Initialize();
	//���t���[������
	virtual void Update();
	//�`�揈��
	virtual void Draw();
};

