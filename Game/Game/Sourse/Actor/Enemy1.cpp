#include "Enemy1.h"
#include "Screen.h"
#include "Util.h"
#include "DxLib.h"
#include "Display.h"

Enemy1::Enemy1(Vector2 *position)
	:Enemy(position,60.0f,1.0f)
{
	angle = atan2(Screen::WinWidth / 2 - position->x, Screen::WinHight / 2 - position->y) + Util::AngleToRadian(-90);
	size = 40;
}


Enemy1::~Enemy1()
{
}

void Enemy1::Initialize()
{
}

void Enemy1::Update()
{
	float speed = 3;
	if (hitSlow)
	{
		speed = 1;
	}
	position->x += velocity->x * speed;
	position->y += velocity->y * speed;
	hitSlow = false;
	Enemy::Update();
}

void Enemy1::Draw()
{

	float r = 20;
	//float radian1 = Util::AngleToRadian(angle);
	float radian2 = angle + Util::AngleToRadian(-120);
	float radian3 = angle + Util::AngleToRadian(120);
	float rotateRadian = Util::AngleToRadian(rotateAngle);
	Display::Instance()->SetScreen(Enemy_Screen);
	DrawTriangle(position->x + r * cos(angle), position->y + r * -sin(angle), position->x + r * cos(radian2), position->y + r * -sin(radian2), position->x + r * cos(radian3), position->y + r * -sin(radian3), GetColor(255, 255, 255), 0);
	DrawTriangle(position->x + r * cos(angle + rotateRadian), position->y + r * -sin(angle + rotateRadian), position->x + r * cos(radian2 + rotateRadian), position->y + r * -sin(radian2 + rotateRadian), position->x + r * cos(radian3 + rotateRadian), position->y + r * -sin(radian3 + rotateRadian), GetColor(255, 255, 255), 0);
}

void Enemy1::Hit(GameObject * obj)
{
	if (obj->GetType() == player ||
		obj->GetType() == player_bullet)
	{
		isDead = true;
	}
	Enemy::Hit(obj);
}
