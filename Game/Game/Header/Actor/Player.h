#pragma once
#include <string>

#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"

class Player :
	public GameObject
{
private:
	Timer bulletTimer;//’e”­Ë‚ÌŠÔŠu
	Timer healTimer;//‰ñ•œ‚ÌŠÔŠu
	int slowBulletNum;//slowBullet‚Ì”
	int putBulletNum;//putBullet‚Ì”
	int maxHp = 10;//‘Ì—Í
	bool operation;
public:
	Player(Vector2 *position);
	~Player();
	//‰Šú‰»
	void Initialize()override;
	//–ˆƒtƒŒ[ƒ€ˆ—
	void Update()override;
	//•`‰æˆ—
	void Draw()override;
	//ƒqƒbƒg‚Ìˆ—
	void Hit(GameObject *obj)override;
	//’Êí’e‚Ì”­Ëˆ—
	void Firing();
	//PutBullet‚Ì”­Ëˆ—
	void FiringPutBullet();
	//SlowBullet‚Ì”­Ëˆ—
	void FiringSlowBullet();
	//–C‘ä‚Ì•`‰æ
	void BatteryDraw();
	//HPƒQ[ƒW‚Ì•`‰æ
	void DrawDamageGauge();
	//ƒAƒCƒRƒ“‚Ì•`‰æ
	void BulletIcon(Vector2 pos,std::string key, std::string name, int Color, int num);
	//‰ñ•œˆ—
	void Heal();
};

