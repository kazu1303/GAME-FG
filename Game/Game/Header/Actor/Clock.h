#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"

class Clock : public GameObject
{
private:
	Timer dayTimer;
	Vector2 clockHand;//針の先端の座標
public:
	Clock(Vector2* position);
	~Clock();
	void Initialize();
	void Update();
	void Draw();
	float GetTime();
};

