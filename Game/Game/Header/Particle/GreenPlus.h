#pragma once
#include "Particle.h"
class GreenPlus :
	public Particle
{
public:
	GreenPlus(Vector2 *position);
	~GreenPlus();
	//‰Šú‰»ˆ—
	virtual void Initialize();
	//–ˆƒtƒŒ[ƒ€ˆ—
	virtual void Update();
	//•`‰æˆ—
	virtual void Draw();
};

