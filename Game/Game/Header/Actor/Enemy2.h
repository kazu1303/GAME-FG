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
	//初期化
	void Initialize()override;
	//毎フレーム処理
	void Update()override;
	//描画処理
	void Draw()override;
	//ヒット時処理
	void Hit(GameObject *obj)override;
};

