#include "Enemy1.h"
#include "Screen.h"
#include "Util.h"
#include "DxLib.h"
#include "Display.h"

Enemy1::Enemy1(Vector2 *position,int hp)
	:Enemy(position,60.0f,1.0f,hp)
{
	angle = atan2(Screen::WinWidth / 2 - position->x, Screen::WinHight / 2 - position->y) + Util::AngleToRadian(-90);
	size = 40;
	defaultSpeed = 3;
	speed = defaultSpeed;
}


Enemy1::~Enemy1()
{
}

//初期化
void Enemy1::Initialize()
{
}

//毎フレーム処理
void Enemy1::Update()
{
	position->x += velocity->x * speed;
	position->y += velocity->y * speed;
	speed = defaultSpeed;
	Enemy::Update();
}

//描画処理
void Enemy1::Draw()
{

	float r = 20;
	float radian2 = angle + Util::AngleToRadian(-120.0f);
	float radian3 = angle + Util::AngleToRadian(120.0f);
	float rotateRadian = Util::AngleToRadian(rotateAngle);
	Display::Instance()->SetScreen(Enemy_Screen);
	DrawTriangle((int)(position->x + r * cos(angle)), (int)(position->y + r * -sin(angle)), (int)(position->x + r * cos(radian2)), (int)(position->y + r * -sin(radian2)), (int)(position->x + r * cos(radian3)), (int)(position->y + r * -sin(radian3)), GetColor(255, 255, 255), 0);
	DrawTriangle((int)(position->x + r * cos(angle + rotateRadian)), (int)(position->y + r * -sin(angle + rotateRadian)), (int)(position->x + r * cos(radian2 + rotateRadian)), (int)(position->y + r * -sin(radian2 + rotateRadian)), (int)(position->x + r * cos(radian3 + rotateRadian)), (int)(position->y + r * -sin(radian3 + rotateRadian)), GetColor(255, 255, 255), 0);
}

//ヒット時処理
void Enemy1::Hit(GameObject * obj)
{
	Enemy::Hit(obj);
}
