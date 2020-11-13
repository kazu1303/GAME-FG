#pragma once
#include "GameObject.h"
#include "Vector2.h"

class EnemyBullet :
	public GameObject
{
public:
	EnemyBullet(Vector2 *position);
	~EnemyBullet();
	//初期化
	void Initialize()override;
	//毎フレーム処理
	void Update()override;
	//描画処理
	void Draw()override;
	//ヒット時処理
	void Hit(GameObject *obj)override;
};

