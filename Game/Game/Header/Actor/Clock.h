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

class Clock : public GameObject
{
private:
	Timer dayTimer;
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
public:
	static Clock& GetInstance();
	Clock(Vector2* position);
	~Clock();
	void Initialize();
	void Update();
	void Draw();
	Color GetSkyColor();
	void DrawSky();
	float GetTime();
};

