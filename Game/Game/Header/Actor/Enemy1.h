#pragma once
#include "Enemy.h"
#include "Vector2.h"

class Enemy1 :
	public Enemy
{
private:

public:
	Enemy1(Vector2 *position,int hp);
	~Enemy1();
	//初期化
	void Initialize()override;
	//毎フレーム処理
	void Update()override;
	//描画処理
	void Draw()override;
	//ヒット時処理
	void Hit(GameObject *obj)override;
};

