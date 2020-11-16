#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"
class SlowBullet :
	public GameObject
{
private:
	Timer deadTimer;//消える時間
public:
	SlowBullet(Vector2 *position,float radian);
	~SlowBullet();
	//初期化
	void Initialize()override;
	//毎フレーム処理
	void Update()override;
	//描画処理
	void Draw()override;
	//ヒット時処理
	void Hit(GameObject *obj)override;
};

