#include "Enemy.h"
#include "Screen.h"


Enemy::Enemy(Vector2 *position, float transTime)
	:GameObject(position,enemy,true)
{
	transTimer = new Timer(transTime, false);
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
	if (Clock::Instance().GetTimeZone() == TimeZone::night && !transTimer->IsTime())
	{
		Transform(TimeZone::night,transTimer->GetRate());
		transTimer->Update();
	}
	if (Clock::Instance().GetTimeZone() == TimeZone::morning && !transTimer->IsTime())
	{
		Transform(TimeZone::morning, transTimer->GetRate());
		transTimer->Update();
	}
	if (Clock::Instance().TimeZoneTrigger())
	{
		transTimer->Reset();
	}
}

void Enemy::Transform(TimeZone timeZone, float rate)
{
	
};
//
//void Enemy::Draw()
//{
//}
//
void Enemy::Hit(GameObject * obj)
{
	if (obj->GetType() == player ||
		obj->GetType() == player_bullet)
	{
		isDead = true;
	}
	if (obj->GetType() == slow_area)
	{
		hitslow = true;
	}
}
