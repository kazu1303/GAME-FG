#include "Enemy.h"
#include "Screen.h"


Enemy::Enemy(Vector2 *position)
	:GameObject(position,enemy,true)
{
	position = new Vector2(position->x, position->y);
	velocity->x = Screen::WinWidth / 2- this->position->x;
	velocity->y = Screen::WinHight  / 2- this->position->y;
	velocity->Normalize();
}


Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
}
