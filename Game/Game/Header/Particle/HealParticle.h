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
	//‰Šú‰»ˆ—
	virtual void Initialize();
	//–ˆƒtƒŒ[ƒ€ˆ—
	virtual void Update();
	//•`‰æˆ—
	virtual void Draw();
};

