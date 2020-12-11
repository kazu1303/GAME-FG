#pragma once
#include "Enemy.h"
#include "Vector2.h"
class TitleEnemy
	:public Enemy
{
private:
	int enemyNum;
	bool inversion;
public:
	TitleEnemy(Vector2 *position);
	~TitleEnemy();
	//初期化
	void Initialize()override;
	//毎フレーム処理
	void Update()override;
	//描画処理
	void Draw()override;
	//ヒット時処理
	void Hit(GameObject *obj)override;
};

