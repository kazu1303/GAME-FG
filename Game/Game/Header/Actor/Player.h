#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"

class Player :
	public GameObject
{
private:
	Timer bulletTimer;
	Timer healTimer;
	int maxSlowBullet = 10;
	int maxPutBullet = 10;
	int maxHp = 10;
public:
	Player(Vector2 *position);
	~Player();
	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Hit(GameObject *obj)override;
	void Firing();
	void FiringPutBullet();
	void FiringSlowBullet();
	void BatteryDraw();
	void DrawDamageGauge();
	void BulletIcon(Vector2 pos,const char* key, const char* name, int Color, int num);
};

