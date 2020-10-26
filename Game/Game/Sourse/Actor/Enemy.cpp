#include "Enemy.h"
#include "Screen.h"
#include "Enemy.h"


Enemy::Enemy(Vector2* position,float maxRotate, float transTime, int hp)
	:GameObject(position,enemy,true,1,hp)
{
	this->maxRotate = maxRotate;
	transTimer = Timer(transTime, false);
	position = new Vector2(position->x, position->y);
	velocity->x = Screen::WinWidth / 2- this->position->x;
	velocity->y = Screen::WinHight  / 2- this->position->y;
	velocity->Normalize();
}


Enemy::~Enemy()
{
}

//void Enemy::Initialize()
//{
//}
//
void Enemy::Update()
{
	if (Clock::Instance().TimeZoneTrigger())
	{
		transTimer.Reset();
		transTimer.Update();
	}
	if (Clock::Instance().GetTimeZone() == TimeZone::night && !transTimer.IsTime())
	{

		Transform(TimeZone::night,transTimer.GetRate());
		transTimer.Update();

	}
	if (Clock::Instance().GetTimeZone() == TimeZone::morning && !transTimer.IsTime())
	{

		Transform(TimeZone::morning, transTimer.GetRate());
		transTimer.Update();
	}
}

void Enemy::Transform(TimeZone timeZone, float rate)
{
	if (position->x >= Screen::WinWidth || position->x <= 0 || position->y >= Screen::WinHight || position->y <= 0)
	{
		transTimer.Max();
	}
	if (timeZone == TimeZone::night)
	{
		rotateAngle = maxRotate * transTimer.GetRate();
	}
	if (timeZone == TimeZone::morning)
	{
		rotateAngle = maxRotate * (1.0f - transTimer.GetRate());
	}
};
//
//void Enemy::Draw()
//{
//}
//
void Enemy::Hit(GameObject * obj)
{
	if (obj->GetType() == player_bullet)
	{
		hp--;
	}
	if (obj->GetType() == player)
	{
		isDead = true;
	}
	if (obj->GetType() == slow_area)
	{
		hitSlow = true;
	}
	if (hp <= 0)
	{
		isDead = true;
	}
}
