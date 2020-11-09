#include "EnemyBullet.h"
#include "DxLib.h"
#include "Screen.h"
#include "Display.h"


EnemyBullet::EnemyBullet(Vector2 *position)
	:GameObject(position,enemy_bullet,true)
{
	velocity->x = Screen::WinWidth / 2 - this->position->x;
	velocity->y = Screen::WinHight / 2 - this->position->y;
	velocity->Normalize();
	attack = 1;
	speed = 3;
}


EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Initialize()
{
}

void EnemyBullet::Update()
{
	position->x += velocity->x * speed;
	position->y += velocity->y * speed;
	if (hp <= 0)
	{
		isDead = true;
	}
}

void EnemyBullet::Draw()
{
	Display::Instance()->SetScreen(PlayerBullet_Screen);
	DrawCircle((int)(position->x), (int)(position->y), 5, GetColor(255, 255, 255), 0);
}

void EnemyBullet::Hit(GameObject * obj)
{
	if (obj->GetType() == player)
	{
		obj->Damege(attack);
	}
}
