#include "Clock.h"
#include "DxLib.h"
#include <math.h>

Clock::Clock(Vector2* position)
	:GameObject(position,clock,false,20,0)
{
	this->position = position;
	dayTimer = Timer(5.0f, true);
}

Clock::~Clock()
{

}

void Clock::Initialize()
{
	
}

void Clock::Update()
{
	dayTimer.Update();
	float rad = dayTimer.GetRate() * 2 * PI;
	float handLength = 25;
	clockHand.x = std::cosf(rad) * 0 - std::sinf(rad) * -handLength + position->x;
	clockHand.y = std::sinf(rad) * 0 + std::cosf(rad) * -handLength + position->y;
}

void Clock::Draw()
{
	DrawCircle(position->x, position->y, 40, GetColor(0, 0, 0), 0);
	DrawLine(position->x, position->y, clockHand.x, clockHand.y,GetColor(0,0,0));
}

float Clock::GetTime()
{
	return dayTimer.GetRate() * 24;
}
