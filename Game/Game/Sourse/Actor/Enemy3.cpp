#include "Enemy3.h"
#include "Screen.h"
#include "Util.h"
#include "Display.h"
#include "DxLib.h"

Enemy3::Enemy3(Vector2 *position,int hp)
	:Enemy(position,45,1,hp)
{
	angle = atan2(Screen::WinWidth / 2 - position->x, Screen::WinHight / 2 - position->y) + Util::AngleToRadian(-90);
	size = 40;
	defaultSpeed = 1.5f;
	speed = defaultSpeed;
}


Enemy3::~Enemy3()
{
}

void Enemy3::Initialize()
{
}

void Enemy3::Update()
{
	position->x += velocity->x * speed;
	position->y += velocity->y * speed;
	speed = defaultSpeed;
	Enemy::Update();
}

void Enemy3::Draw()
{
	float r = size / 2;
	//float radian1 = Util::AngleToRadian(angle);
	float radian2 = angle + Util::AngleToRadian(-90);
	float radian3 = angle + Util::AngleToRadian(90);
	float radian4 = angle + Util::AngleToRadian(180);
	Display::Instance()->SetScreen(Enemy_Screen);
	DrawLine(position->x + r * cos(angle), position->y + r * -sin(angle), position->x + r * cos(radian2), position->y + r * -sin(radian2), GetColor(255, 255, 255));
	DrawLine(position->x + r * cos(angle), position->y + r * -sin(angle), position->x + r * cos(radian3), position->y + r * -sin(radian3), GetColor(255, 255, 255));
	DrawLine(position->x + r * cos(radian4), position->y + r * -sin(radian4), position->x + r * cos(radian2), position->y + r * -sin(radian2), GetColor(255, 255, 255));
	DrawLine(position->x + r * cos(radian4), position->y + r * -sin(radian4), position->x + r * cos(radian3), position->y + r * -sin(radian3), GetColor(255, 255, 255));
	float rotateRadian = Util::AngleToRadian(rotateAngle);
	DrawLine(position->x + r * cos(angle + rotateRadian), position->y + r * -sin(angle + rotateRadian), position->x + r * cos(radian2 + rotateRadian), position->y + r * -sin(radian2 + rotateRadian), GetColor(255, 255, 255));
	DrawLine(position->x + r * cos(angle + rotateRadian), position->y + r * -sin(angle + rotateRadian), position->x + r * cos(radian3 + rotateRadian), position->y + r * -sin(radian3 + rotateRadian), GetColor(255, 255, 255));
	DrawLine(position->x + r * cos(radian4 + rotateRadian), position->y + r * -sin(radian4 + rotateRadian), position->x + r * cos(radian2 + rotateRadian), position->y + r * -sin(radian2 + rotateRadian), GetColor(255, 255, 255));
	DrawLine(position->x + r * cos(radian4 + rotateRadian), position->y + r * -sin(radian4 + rotateRadian), position->x + r * cos(radian3 + rotateRadian), position->y + r * -sin(radian3 + rotateRadian), GetColor(255, 255, 255));
	//DrawBox(position->x + r * cos(angle), position->y + r * -sin(angle), position->x + r * cos(radian2), position->y + r * -sin(radian2),GetColor(255, 255, 255), 0);
}

void Enemy3::Hit(GameObject * obj)
{
	Enemy::Hit(obj);
}
