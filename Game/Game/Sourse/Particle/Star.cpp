#include "Star.h"
#include "Util.h"
#include "DxLib.h"
#include <cmath>

Star::Star(Vector2 *position)
	:Particle(position)
{
	scale = GetRand(50) + 10;
	deadTimer = Timer(3.0f, false);
	angle = 0;
	addAngle = GetRand(20) - 10;
}


Star::~Star()
{
}

void Star::Initialize()
{
	
}

void Star::Update()
{
	angle += addAngle;
	deadTimer.Update();
	if (deadTimer.IsTime())
	{
		isDead = true;
	}
}

void Star::Draw()
{
	
	float radian1 = Util::AngleToRadian(angle + 0);
	float radian2 = Util::AngleToRadian(angle + 72);
	float radian3 = Util::AngleToRadian(angle + 144);
	float radian4 = Util::AngleToRadian(angle + 216);
	float radian5 = Util::AngleToRadian(angle + 288);
	Vector2 vertex[5] =
	{
		Vector2(position->x + scale * cos(radian1), position->y + scale * -sin(radian1)),
		Vector2(position->x + scale * cos(radian2), position->y + scale * -sin(radian2)),
		Vector2(position->x + scale * cos(radian3), position->y + scale * -sin(radian3)),
		Vector2(position->x + scale * cos(radian4), position->y + scale * -sin(radian4)),
		Vector2(position->x + scale * cos(radian5), position->y + scale * -sin(radian5))
	};
	SetDrawBlendMode(DX_BLENDMODE_ADD, 255 * (1 - std::abs(0.5f - (float)(deadTimer.GetRate()) * 2)));
	DrawLine((int)vertex[0].x, (int)vertex[0].y, (int)vertex[2].x, (int)vertex[2].y, GetColor(255, 255, 0));
	DrawLine((int)vertex[2].x, (int)vertex[2].y, (int)vertex[4].x, (int)vertex[4].y, GetColor(255, 255, 0));
	DrawLine((int)vertex[4].x, (int)vertex[4].y, (int)vertex[1].x, (int)vertex[1].y, GetColor(255, 255, 0));
	DrawLine((int)vertex[1].x, (int)vertex[1].y, (int)vertex[3].x, (int)vertex[3].y, GetColor(255, 255, 0));
	DrawLine((int)vertex[3].x, (int)vertex[3].y, (int)vertex[0].x, (int)vertex[0].y, GetColor(255, 255, 0));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
