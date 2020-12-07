#include "Enemy.h"
#include "Screen.h"
#include "Enemy.h"
#include "DeadParticle.h"


Enemy::Enemy(Vector2* position,float maxRotate, float transTime, int hp)
	:GameObject(position,enemy,true,1,hp)
{
	this->maxRotate = maxRotate;
	transTimer = Timer(transTime, false);
	velocity->x = Screen::WinWidth / 2- this->position->x;
	velocity->y = Screen::WinHight  / 2- this->position->y;
	velocity->Normalize();
	attack = 1;
}


Enemy::~Enemy()
{
	for (int i = 0; i < 100; i++)
	{
		new DeadParticle(new Vector2(position->x, position->y));
	}
}

//void Enemy::Initialize()
//{
//}
//

//毎フレーム処理
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
	if (hp <= 0)
	{
		isDead = true;

	}
	float lengthX = position->x - Screen::WinWidth / 2;
	float lengthY = position->y - Screen::WinHight / 2;
	float length = sqrtf(lengthX * lengthX + lengthY * lengthY);
	if (length >= 600)
	{
		isDead = true;
	}
}

//変形処理
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

//ヒット時処理
void Enemy::Hit(GameObject * obj)
{
	if (obj->GetType() == player_bullet)
	{
		obj->Damege(attack);
	}
	if (obj->GetType() == player)
	{
		obj->Damege(attack);
	}
}
