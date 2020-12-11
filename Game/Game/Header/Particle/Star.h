#pragma once
#include "Particle.h"
#include "Vector2.h"
#include "Timer.h"
class Star :
	public Particle
{
private:
	int angle;
	Timer deadTimer;
	int addAngle;
public:
	Star(Vector2 *position);
	~Star();
	//‰Šú‰»ˆ—
	virtual void Initialize()override;
	//–ˆƒtƒŒ[ƒ€ˆ—
	virtual void Update()override;
	//•`‰æˆ—
	virtual void Draw()override;
};

