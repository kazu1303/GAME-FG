#include "Controller.h"
#include "DxLib.h"
#include <string>
#include <stdio.h>

Controller* Controller::instance;


Controller::Controller()
{
	SetJoypadDeadZone(DX_INPUT_PAD1, 0.5f);
	int x, y;
	GetJoypadAnalogInput(&x, &y, DX_INPUT_KEY_PAD1);
	direction.x = x;
	direction.y = y;
	instance = this;
}


Controller::~Controller()
{
}

Controller * Controller::Instance()
{
	return instance;
}

void Controller::Update()
{
	int x, y;
	GetJoypadAnalogInput(&x, &y, DX_INPUT_KEY_PAD1);
	if (!(x == 0 && y == 0))
	{
		direction.x = x;
		direction.y = y;
	}
	DrawString(100, 400, std::to_string(direction.x).c_str() , GetColor(255, 255, 255));
	DrawString(100, 420, std::to_string(direction.y).c_str(), GetColor(255, 255, 255));
}

Vector2 Controller::DirectionCoordinate()
{
	return direction;
}

bool Controller::GetKey(int key)
{
	if ((GetJoypadInputState(DX_INPUT_KEY_PAD1) & key) != 0)
	{
		return true;
	}
	return false;
}
