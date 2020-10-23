#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"
#include "Clock.h"
class Enemy :
	public GameObject
{
private:
	Timer* transTimer;
	bool isTransform;
protected:
	bool hitslow = false;
public:
	Enemy(Vector2 *position, float transTime = 1.0f);
	~Enemy();
	virtual void Initialize()override = 0;
	virtual void Update()override = 0;
	virtual void Draw()override = 0;
	virtual void Hit(GameObject *obj)override = 0;
	virtual void Transform(TimeZone timeZone,float rate);
};

