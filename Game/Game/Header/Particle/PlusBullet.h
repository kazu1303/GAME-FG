#pragma once
#include "Particle.h"
class PlusBullet :
	public Particle
{
public:
	PlusBullet(Vector2 *position);
	~PlusBullet();
	//‰Šú‰»ˆ—
	virtual void Initialize();
	//–ˆƒtƒŒ[ƒ€ˆ—
	virtual void Update();
	//•`‰æˆ—
	virtual void Draw();
};

