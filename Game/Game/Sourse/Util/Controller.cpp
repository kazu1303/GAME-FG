#include "Controller.h"
#include "DxLib.h"
#include "Util.h"
#include <string>
#include <stdio.h>

Controller* Controller::instance;


Controller::Controller()
{
	SetJoypadDeadZone(DX_INPUT_PAD1, 0.5f);
	GetJoypadDirectInputState(DX_INPUT_KEY_PAD1, &current);
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
	prev = current;
	for (int i = 0; i < 28; i++)
	{
		prevbutton[i] = currentbutton[i];
	}
	int x, y;
	GetJoypadAnalogInput(&x, &y, DX_INPUT_KEY_PAD1);
	if (!(x == 0 && y == 0))
	{
		direction.x = x;
		direction.y = y;
	}

	
	GetJoypadDirectInputState(DX_INPUT_KEY_PAD1, &current);
	for (int i = 0; i < 28; i++)
	{
		if (current.Buttons[i] != 0)
		{
			currentbutton[i] = true;
		}
		else
		{
			currentbutton[i] = false;
		}

	}
}

Vector2 Controller::DirectionCoordinate()
{
	return direction;
}

bool Controller::GetKey(int key)
{
	int num = Util::Index(key) - 4;
	if (currentbutton[num] && !prevbutton[num])
	{
		return true;
	}
	return false;
}

void Controller::Draw()
{
	DrawString(100, 400, std::to_string(direction.x).c_str(), GetColor(255, 255, 255));
	DrawString(100, 420, std::to_string(direction.y).c_str(), GetColor(255, 255, 255));
	DrawFormatString(0, 48, GetColor(255, 255, 255), "POV 0:%d 1:%d 2:%d 3:%d",
		prev.POV[0], prev.POV[1],
		prev.POV[2], prev.POV[3]);
	for (int i = 0; i < 32; i++)
	{
		DrawFormatString(64 + i % 8 * 64, 64 + i / 8 * 16, GetColor(255,255,255),
			"%2d:%d", i, prev.Buttons[i]);
	}
}
