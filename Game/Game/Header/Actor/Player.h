#pragma once
#include <string>

#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"

class Player :
	public GameObject
{
private:
	Timer bulletTimer;//弾発射の間隔
	Timer healTimer;//回復の間隔
	Timer deadTimer;
	Timer quakeTimer;
	int slowBulletNum;//slowBulletの数
	int putBulletNum;//putBulletの数
	int maxHp = 10;//体力
	bool operation;
	Timer damegeTimer;
	bool drawDamageEffect;
	Timer blinkingTimer;
public:
	Player(Vector2 *position);
	~Player();
	//初期化
	void Initialize()override;
	//毎フレーム処理
	void Update()override;
	//描画処理
	void Draw()override;
	//ヒット時の処理
	void Hit(GameObject *obj)override;
	//通常弾の発射処理
	void Firing();
	//PutBulletの発射処理
	void FiringPutBullet();
	//SlowBulletの発射処理
	void FiringSlowBullet();
	//砲台の描画
	void BatteryDraw();
	//HPゲージの描画
	void DrawDamageGauge();
	//アイコンの描画
	void BulletIcon(Vector2 pos,std::string key, std::string name, int Color, int num);
	//回復処理
	void Heal();

	void DrawDead();

	void DrawDamageEffect();

	int GetHp();
};

