#include "Enemy3.h"
#include "Screen.h"
#include "Util.h"
#include "Display.h"
#include "DxLib.h"

Enemy3::Enemy3(Vector2 *position,int hp)
	:Enemy(position,45,1,hp)
{
	angle = atan2(Screen::WinWidth / 2 - this->position->x, Screen::WinHight / 2 - this->position->y) + Util::AngleToRadian(-90);
	size = 40;
	defaultSpeed = 0.5f;
	speed = defaultSpeed;
}


Enemy3::~Enemy3()
{
}

//初期化
void Enemy3::Initialize()
{
}

//毎フレーム処理
void Enemy3::Update()
{
	position->x += velocity->x * speed;
	position->y += velocity->y * speed;
	speed = defaultSpeed;
	Enemy::Update();
}

//描画処理
void Enemy3::Draw()
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
	//DrawBox(position->x + r * cos(angle), position->y + r * -sin(angle), position->x + r * cos(radian2), position->y + r * -sin(radian2),GetColor(255, 255, 255), 0);
}

//ヒット時処理
void Enemy3::Hit(GameObject * obj)
{
	Enemy::Hit(obj);
}
