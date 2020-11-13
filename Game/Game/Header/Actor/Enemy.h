#pragma once 
#include "GameObject.h" 
#include "Vector2.h" 
#include "Timer.h" 
#include "Clock.h" 

class Enemy :
	public GameObject
{
private:

	//bool isTransform;
protected:
	Timer transTimer;
	float maxRotate = 0;
	float rotateAngle = 0;
	bool hitSlow = false;	
public:
	Enemy(Vector2 *position, float maxRotate = 45.0f,float transTime = 2.0f, int hp = 1);
	~Enemy();
	//初期化
	virtual void Initialize()override = 0;
	//毎フレーム処理
	virtual void Update()override = 0;
	//描画処理
	virtual void Draw()override = 0;
	//ヒット時処理
	virtual void Hit(GameObject *obj)override = 0;
	//変形処理
	virtual void Transform(TimeZone timeZone, float rate);
};

