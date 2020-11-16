#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"
class PutBullet :
	public GameObject
{
private :
public:
	PutBullet(Vector2 *position, float radian);
	~PutBullet();
	//初期化処理
	void Initialize()override;
	//毎フレーム処理
	void Update()override;
	//描画処理
	void Draw()override;
	//ヒット時処理
	void Hit(GameObject *obj)override;
	//ダメージ計算
	void Damege(int attack)override;
};

