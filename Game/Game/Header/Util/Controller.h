#pragma once
#include "Vector2.h"
#include "DxLib.h"
class Controller
{
private:
	static Controller* instance;
	Vector2 direction;
public:
	Controller();
	~Controller();
	static Controller* Instance();
	void Update();
	Vector2 DirectionCoordinate();
	bool GetKey(int key);
};

