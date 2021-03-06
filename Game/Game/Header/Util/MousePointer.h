#pragma once
#include"Vector2.h"
class MousePointer
{
private:
	static MousePointer* instance;
	Vector2 position;
public:
	MousePointer();
	~MousePointer();
	static MousePointer* Instance();
	//毎フレーム処理
	void Update();
	//座標の取得
	Vector2 GetPosition();
	//描画処理
	void Draw();
};

