#pragma once
#include "Particle.h"

class DeadParticle : public Particle
{
private:
	float speed;
public:
	DeadParticle(Vector2* position);
	~DeadParticle();
	//‰Šú‰»ˆ—
	virtual void Initialize();
	//–ˆƒtƒŒ[ƒ€ˆ—
	virtual void Update();
	//•`‰æˆ—
	virtual void Draw();
};
