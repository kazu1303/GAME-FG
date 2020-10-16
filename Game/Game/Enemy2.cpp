#include "Enemy2.h"
#include "Screen.h"
#include "Util.h"


Enemy2::Enemy2(Vector2 *position)
	:Enemy(position)
{
	angle = atan2(Screen::WinWidth / 2 - position->x, Screen::WinHight / 2 - position->y) + Util::AngleToRadian(-90);
	size = 40;
	sizeY = 30;
}


Enemy2::~Enemy2()
{
}

void Enemy2::Initialize()
{
}

void Enemy2::Update()
{
}

void Enemy2::Draw()
{
}

void Enemy2::Hit(GameObject * obj)
{
}
