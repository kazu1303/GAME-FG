#include "Enemy2.h"
#include "Screen.h"
#include "Util.h"
#include "Display.h"
#include "DxLib.h"

Enemy2::Enemy2(Vector2 *position)
	:Enemy(position,1)
{
	angle = atan2(Screen::WinWidth / 2 - position->x, Screen::WinHight / 2 - position->y) + Util::AngleToRadian(-90);
	size = 40;
	defaultSpeed = 3;
	speed = defaultSpeed;
}


Enemy2::~Enemy2()
{
}

void Enemy2::Initialize()
{
}

void Enemy2::Update()
{
	position->x += velocity->x * speed;
	position->y += velocity->y * speed;
	speed = defaultSpeed;
}

void Enemy2::Draw()
{
	float r = size / 2;
	float radian2 = angle + Util::AngleToRadian(-120);
	float radian3 = angle + Util::AngleToRadian(120);
	Display::Instance()->SetScreen(Enemy_Screen);
	DrawTriangle(position->x + r * cos(angle), position->y + r * -sin(angle), position->x + r * cos(radian2), position->y + r * -sin(radian2), position->x + r * cos(radian3), position->y + r * -sin(radian3), GetColor(255, 255, 255), 0);
	DrawTriangle(position->x - r * cos(angle), position->y - r * -sin(angle), position->x - r * cos(radian2), position->y - r * -sin(radian2), position->x - r * cos(radian3), position->y - r * -sin(radian3), GetColor(255, 255, 255), 0);
}

void Enemy2::Hit(GameObject * obj)
{
	Enemy::Hit(obj);
}
