#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"

struct Color
{
	int r;
	int g;
	int b;
};

enum TimeZone
{
	morning,
	night
};

class Clock : public GameObject
{
private:
	Timer dayTimer;//1日の時間
	Vector2 clockHand;//針の先端の座標
	static Clock* instance;
	static const int skyColorLength = 6;
	Color skyColors[skyColorLength] = {
		{ 155, 177, 177 },
		{ 210, 255, 255 },
		{ 255, 72, 0 },
		{ 85, 24, 0 },
		{ 42, 12, 0 },
		{ 0, 0, 0 },
	};
	TimeZone timeZone;//現在の時間帯
	TimeZone prevTimeZone;//一つ前の時間帯
	TimeZone currentTimeZone;//現在の時間帯
	bool timeZoneTrigger;//時間帯が切り替わった瞬間
	int day;//経過日時
public:
	static Clock& Instance();
	Clock(Vector2* position);
	~Clock();
	//初期化処理
	void Initialize();
	//毎フレーム処理
	void Update();
	//描画処理
	void Draw();
	//空の色の取得
	Color GetSkyColor();
	//空の描画
	void DrawSky();
	//経過時間
	float GetTime();
	//時間帯の取得
	TimeZone GetTimeZone();
	//時間帯が切り替わったか
	bool TimeZoneTrigger();
	//経過日
	int GetElapsedTime();
};

