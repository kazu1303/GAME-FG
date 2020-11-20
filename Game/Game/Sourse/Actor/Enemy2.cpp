#include "Enemy2.h"
#include "Screen.h"
#include "Util.h"
#include "Display.h"
#include "DxLib.h"
#include "EnemyBullet.h"

Enemy2::Enemy2(Vector2 *position,int hp)
	:Enemy(position,36,1.0f,hp)
{
	angle = atan2(Screen::WinWidth / 2 - this->position->x, Screen::WinHight / 2 - this->position->y) + Util::AngleToRadian(-90);
	posAngle = atan2(Screen::WinWidth / 2 - this->position->x, Screen::WinHight / 2 - this->position->y) + Util::AngleToRadian(90);
	size = 40;
	defaultSpeed = 3;
	speed = defaultSpeed;
	firing = false;
	bulletTimer = Timer(2.0f, true);
}


Enemy2::~Enemy2()
{
}

//初期化
void Enemy2::Initialize()
{
}

//毎フレーム処理
void Enemy2::Update()
{
	float lengthX = position->x - Screen::WinWidth / 2;
	float lengthY = position->y - Screen::WinHight / 2;
	float length = sqrtf(lengthX * lengthX + lengthY * lengthY);
	if (!(length <= 300))
	{
		position->x += velocity->x * speed;
		position->y += velocity->y * speed;
	}
	else
	{
		if (Clock::Instance().GetTimeZone() == morning || firing)
		{
			if (!firing && 0 == GetRand(500))
			{
				firing = true;
			}

			if (firing)
			{
				velocity->x = Screen::WinWidth / 2 - this->position->x;
				velocity->y = Screen::WinHight / 2 - this->position->y;
				velocity->Normalize();
				position->x += velocity->x * speed;
				position->y += velocity->y * speed;
			}
			else
			{
				posAngle += Util::AngleToRadian(1);
				position->x = Screen::WinWidth / 2 + length * cos(posAngle);
				position->y = Screen::WinHight / 2 + length * -sin(posAngle);

			}
		}
		else if (Clock::Instance().GetTimeZone() == night && !firing)
		{
			posAngle += Util::AngleToRadian(1);
			position->x = Screen::WinWidth / 2 + length * cos(posAngle);
			position->y = Screen::WinHight / 2 + length * -sin(posAngle);
			bulletTimer.Update();
			if (bulletTimer.IsTime())
			{
				new EnemyBullet(new Vector2(position->x,position->y));
			}
		}
	}

	speed = defaultSpeed;
	Enemy::Update();
}

//描画処理
void Enemy2::Draw()
{
	float r = size / 2;
	angle = atan2(Screen::WinWidth / 2 - position->x, Screen::WinHight / 2 - position->y) + Util::AngleToRadian(-90);
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

//ヒット時処理
void Enemy2::Hit(GameObject * obj)
{
	Enemy::Hit(obj);
}
