#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"

class Player :
	public GameObject
{
private:
	Timer bulletTimer;
public:
	Player(Vector2 *position);
	~Player();
	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Firing();
	void BatteryDraw();
};

