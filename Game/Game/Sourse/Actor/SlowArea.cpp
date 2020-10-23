#include "SlowArea.h"
#include "DxLib.h"
#include "Display.h"
#include "Screen.h"


SlowArea::SlowArea(Vector2 *position)
	:GameObject(position,slow_area,true)
{
	deadTimer = Timer(3.0f, false);
	size = 0;
}


SlowArea::~SlowArea()
{
}

void SlowArea::Initialize()
{
}

void SlowArea::Update()
{
	if (size < 100)
	{
		size += 4;
	}
	deadTimer.Update();
	if (deadTimer.IsTime())
	{
		isDead = true;
	}
}

void SlowArea::Draw()
{
	Display::Instance()->SetScreen(PlayerBullet_Screen);
	DrawCircle(position->x, position->y, size / 2, GetColor(255, 255, 255), 0);
}
