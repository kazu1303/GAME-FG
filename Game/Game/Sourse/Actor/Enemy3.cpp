#include "Enemy3.h"
#include "Screen.h"
#include "Util.h"
#include "Display.h"
#include "DxLib.h"

Enemy3::Enemy3(Vector2 *position)
	:Enemy(position,3)
{
	angle = atan2(Screen::WinWidth / 2 - position->x, Screen::WinHight / 2 - position->y) + Util::AngleToRadian(-90);
	size = 40;
}


Enemy3::~Enemy3()
{
}

void Enemy3::Initialize()
{
}

void Enemy3::Update()
{
	float speed = 1.5f;
	position->x += velocity->x * speed;
	position->y += velocity->y * speed;
}

void Enemy3::Draw()
{
	float r = size / 2;
	//float radian1 = Util::AngleToRadian(angle);
	float radian2 = angle + Util::AngleToRadian(-120);
	float radian3 = angle + Util::AngleToRadian(120);
	Display::Instance()->SetScreen(Enemy_Screen);
	DrawBox(position->x + r * cos(angle), position->y + r * -sin(angle), position->x + r * cos(radian2), position->y + r * -sin(radian2),GetColor(255, 255, 255), 0);
}

void Enemy3::Hit(GameObject * obj)
{
	if (obj->GetType() == player ||
		obj->GetType() == player_bullet)
	{
		hp--;
		if (hp <= 0)isDead = true;
	}
}
