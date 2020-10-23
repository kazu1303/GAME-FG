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
	float maxRotate = 0;
	float rotateAngle = 0;
	bool hitSlow = false;	
public:
	Enemy(Vector2 *position, float maxRotate = 45.0f,float transTime = 2.0f, int hp = 1);
	~Enemy();
	virtual void Initialize()override = 0;
	virtual void Update()override = 0;
	virtual void Draw()override = 0;
	virtual void Hit(GameObject *obj)override = 0;
	virtual void Transform(TimeZone timeZone, float rate);
};

