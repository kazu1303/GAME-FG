#include "TitleEnemy.h"
#include "DxLib.h"
#include "Util.h"
#include "DisPlay.h"
#include "Screen.h"

TitleEnemy::TitleEnemy(Vector2 *position)
	:Enemy(position, enemy, 1, 1)
{
	enemyNum = GetRand(3) + 1;
	inversion = false;
	angle = atan2(Screen::WinWidth / 2 - this->position->x, Screen::WinHight / 2 - this->position->y) + Util::AngleToRadian(-90);
	size = 40;
	defaultSpeed = 3;
	speed = defaultSpeed;
}


TitleEnemy::~TitleEnemy()
{
}

void TitleEnemy::Initialize()
{
}

void TitleEnemy::Update()
{
	float lengthX = position->x - Screen::WinWidth / 2;
	float lengthY = position->y - Screen::WinHight / 2;
	float length = sqrtf(lengthX * lengthX + lengthY * lengthY);
	if (!(length <= 300))
	{
		inversion = true;
	}
	if (inversion)
	{
		position->x += velocity->x * -speed;
		position->y += velocity->y * -speed;
		speed = defaultSpeed;
	}
	else
	{
		position->x += velocity->x * -speed;
		position->y += velocity->y * -speed;
		speed = defaultSpeed;
	}
	Enemy::Update();
}

void TitleEnemy::Draw()
{
	if (enemyNum == 1)
	{
		float r = 20;
		float radian2 = angle + Util::AngleToRadian(-120.0f);
		float radian3 = angle + Util::AngleToRadian(120.0f);
		float rotateRadian = Util::AngleToRadian(rotateAngle);
		Display::Instance()->SetScreen(Enemy_Screen);
		DrawTriangle((int)(position->x + r * cos(angle)), (int)(position->y + r * -sin(angle)), (int)(position->x + r * cos(radian2)), (int)(position->y + r * -sin(radian2)), (int)(position->x + r * cos(radian3)), (int)(position->y + r * -sin(radian3)), GetColor(255, 255, 255), 0);
		DrawTriangle((int)(position->x + r * cos(angle + rotateRadian)), (int)(position->y + r * -sin(angle + rotateRadian)), (int)(position->x + r * cos(radian2 + rotateRadian)), (int)(position->y + r * -sin(radian2 + rotateRadian)), (int)(position->x + r * cos(radian3 + rotateRadian)), (int)(position->y + r * -sin(radian3 + rotateRadian)), GetColor(255, 255, 255), 0);
	}
	else if (enemyNum == 2)
	{
		float r = size / 2;
		//float radian1 = Util::AngleToRadian(angle);
		float radian2 = angle + Util::AngleToRadian(72);
		float radian3 = angle + Util::AngleToRadian(144);
		float radian4 = angle + Util::AngleToRadian(216);
		float radian5 = angle + Util::AngleToRadian(288);
		Display::Instance()->SetScreen(Enemy_Screen);
		DrawLine((int)(position->x + r * cos(angle)), (int)(position->y + r * -sin(angle)), (int)(position->x + r * cos(radian2)), (int)(position->y + r * -sin(radian2)), GetColor(255, 255, 255));
		DrawLine((int)(position->x + r * cos(radian2)), (int)(position->y + r * -sin(radian2)), (int)(position->x + r * cos(radian3)), (int)(position->y + r * -sin(radian3)), GetColor(255, 255, 255));
		DrawLine((int)(position->x + r * cos(radian3)), (int)(position->y + r * -sin(radian3)), (int)(position->x + r * cos(radian4)), (int)(position->y + r * -sin(radian4)), GetColor(255, 255, 255));
		DrawLine((int)(position->x + r * cos(radian4)), (int)(position->y + r * -sin(radian4)), (int)(position->x + r * cos(radian5)), (int)(position->y + r * -sin(radian5)), GetColor(255, 255, 255));
		DrawLine((int)(position->x + r * cos(radian5)), (int)(position->y + r * -sin(radian5)), (int)(position->x + r * cos(angle)), (int)(position->y + r * -sin(angle)), GetColor(255, 255, 255));
		float rotateRadian = Util::AngleToRadian(rotateAngle);
		DrawLine((int)(position->x + r * cos(angle + rotateRadian)), (int)(position->y + r * -sin(angle + rotateRadian)), (int)(position->x + r * cos(radian2 + rotateRadian)), (int)(position->y + r * -sin(radian2 + rotateRadian)), GetColor(255, 255, 255));
		DrawLine((int)(position->x + r * cos(radian2 + rotateRadian)), (int)(position->y + r * -sin(radian2 + rotateRadian)), (int)(position->x + r * cos(radian3 + rotateRadian)), (int)(position->y + r * -sin(radian3 + rotateRadian)), GetColor(255, 255, 255));
		DrawLine((int)(position->x + r * cos(radian3 + rotateRadian)), (int)(position->y + r * -sin(radian3 + rotateRadian)), (int)(position->x + r * cos(radian4 + rotateRadian)), (int)(position->y + r * -sin(radian4 + rotateRadian)), GetColor(255, 255, 255));
		DrawLine((int)(position->x + r * cos(radian4 + rotateRadian)), (int)(position->y + r * -sin(radian4 + rotateRadian)), (int)(position->x + r * cos(radian5 + rotateRadian)), (int)(position->y + r * -sin(radian5 + rotateRadian)), GetColor(255, 255, 255));
		DrawLine((int)(position->x + r * cos(radian5 + rotateRadian)), (int)(position->y + r * -sin(radian5 + rotateRadian)), (int)(position->x + r * cos(angle + rotateRadian)), (int)(position->y + r * -sin(angle + rotateRadian)), GetColor(255, 255, 255));
	}
	else
	{
		float r = size / 2;
		//float radian1 = Util::AngleToRadian(angle);
		float radian2 = angle + Util::AngleToRadian(-90);
		float radian3 = angle + Util::AngleToRadian(90);
		float radian4 = angle + Util::AngleToRadian(180);
		Display::Instance()->SetScreen(Enemy_Screen);
		DrawLine((int)(position->x + r * cos(angle)), (int)(position->y + r * -sin(angle)), (int)(position->x + r * cos(radian2)), (int)(position->y + r * -sin(radian2)), GetColor(255, 255, 255));
		DrawLine((int)(position->x + r * cos(angle)), (int)(position->y + r * -sin(angle)), (int)(position->x + r * cos(radian3)), (int)(position->y + r * -sin(radian3)), GetColor(255, 255, 255));
		DrawLine((int)(position->x + r * cos(radian4)), (int)(position->y + r * -sin(radian4)), (int)(position->x + r * cos(radian2)), (int)(position->y + r * -sin(radian2)), GetColor(255, 255, 255));
		DrawLine((int)(position->x + r * cos(radian4)), (int)(position->y + r * -sin(radian4)), (int)(position->x + r * cos(radian3)), (int)(position->y + r * -sin(radian3)), GetColor(255, 255, 255));
		float rotateRadian = Util::AngleToRadian(rotateAngle);
		DrawLine((int)(position->x + r * cos(angle + rotateRadian)), (int)(position->y + r * -sin(angle + rotateRadian)), (int)(position->x + r * cos(radian2 + rotateRadian)), (int)(position->y + r * -sin(radian2 + rotateRadian)), GetColor(255, 255, 255));
		DrawLine((int)(position->x + r * cos(angle + rotateRadian)), (int)(position->y + r * -sin(angle + rotateRadian)), (int)(position->x + r * cos(radian3 + rotateRadian)), (int)(position->y + r * -sin(radian3 + rotateRadian)), GetColor(255, 255, 255));
		DrawLine((int)(position->x + r * cos(radian4 + rotateRadian)), (int)(position->y + r * -sin(radian4 + rotateRadian)), (int)(position->x + r * cos(radian2 + rotateRadian)), (int)(position->y + r * -sin(radian2 + rotateRadian)), GetColor(255, 255, 255));
		DrawLine((int)(position->x + r * cos(radian4 + rotateRadian)), (int)(position->y + r * -sin(radian4 + rotateRadian)), (int)(position->x + r * cos(radian3 + rotateRadian)), (int)(position->y + r * -sin(radian3 + rotateRadian)), GetColor(255, 255, 255));
	}
}

void TitleEnemy::Hit(GameObject * obj)
{
	Enemy::Hit(obj);
}
