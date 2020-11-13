#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"
class SlowArea :
	public GameObject
{
private:
	Timer deadTimer;//消える時間
public:
	SlowArea(Vector2 *position);
	~SlowArea();
	//初期化
	void Initialize()override;
	//毎フレーム処理
	void Update()override;
	//描画処理
	void Draw()override;
	//ヒット時処理
	void Hit(GameObject *obj)override;
};

