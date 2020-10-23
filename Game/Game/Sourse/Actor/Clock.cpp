#include "Clock.h"
#include "DxLib.h"
#include "Screen.h"
#include "Display.h"
#include <math.h>

Clock* Clock::instance = nullptr;

Clock& Clock::Instance()
{
	return *instance;
}

Clock::Clock(Vector2* position)
	:GameObject(position, clock, false, 20, 0)
{
	instance = this;
	this->position = position;
	dayTimer = Timer(30.0f, true);
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
	if (GetTime() > 12)
	{
		timeZone = night;
	}
	else
	{
		timeZone = morning;
	}
}

void Clock::Draw()
{
	Display::Instance()->SetScreen(SkyColor_Screen);
	SetDrawBlendMode(DX_BLENDMODE_ADD, 180);
	DrawSky();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawCircle(position->x, position->y, 40, GetColor(0, 0, 0), 0);
	DrawLine(position->x, position->y, clockHand.x, clockHand.y, GetColor(0, 0, 0));
}

Color Clock::GetSkyColor()
{
	int colorIndex = (int)(dayTimer.GetRate() * skyColorLength);
	float colorLocation = dayTimer.GetRate() * skyColorLength - colorIndex;
	if (colorIndex == skyColorLength)
	{
		return skyColors[0];
	}
	Color startColor = skyColors[colorIndex];
	if (colorIndex == skyColorLength - 1)
	{
		colorIndex = -1;
	}
	Color endColor = skyColors[colorIndex + 1];
	int rate = 6;
	return Color{
		startColor.r + (int)((endColor.r - startColor.r) * colorLocation) + (255 - (startColor.r + (int)((endColor.r - startColor.r) * colorLocation))) / rate,
		startColor.g + (int)((endColor.g - startColor.g) * colorLocation) + (255 - (startColor.g + (int)((endColor.g - startColor.g) * colorLocation))) / rate,
		startColor.b + (int)((endColor.b - startColor.b) * colorLocation) + (255 - (startColor.b + (int)((endColor.b - startColor.b) * colorLocation))) / rate,
	};
}

void Clock::DrawSky()
{
	DrawBox(0, 0, Screen::WinWidth, Screen::WinHight,GetColor(GetSkyColor().r,GetSkyColor().g,GetSkyColor().b),TRUE);
}

float Clock::GetTime()
{
	return dayTimer.GetRate() * 24;
}

TimeZone Clock::GetTimeZone()
{
	return timeZone;
}
