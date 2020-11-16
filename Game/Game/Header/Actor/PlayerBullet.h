#pragma once
#include "GameObject.h"
#include "Vector2.h"

class PlayerBullet :
	public GameObject
{
public:
	PlayerBullet(Vector2 *position, float radian);
	~PlayerBullet();
	//初期化
	void Initialize()override;
	//毎フレーム処理
	void Update()override;
	//ヒット時処理
	void Hit(GameObject* obj) override;
	//描画処理
	void Draw()override;
};

