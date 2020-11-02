#pragma once
#include "Enemy.h"
#include "Vector2.h"
#include "Timer.h"
class Enemy2 :
	public Enemy
{
private:
	float posAngle;
	bool firing;
	Timer bulletTimer;
public:
	Enemy2(Vector2 *position,int hp);
	~Enemy2();
	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Hit(GameObject *obj)override;
};

