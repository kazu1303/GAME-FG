#include "PlayerBullet.h"
#include "MousePointer.h"
#include "DxLib.h"
#include "Screen.h"
#include "Display.h"
#include "Controller.h"

PlayerBullet::PlayerBullet(Vector2 *position)
	:GameObject(position,player_bullet,true)
{
	position = new Vector2(position->x, position->y);
	Vector2 mouse = Controller::Instance()->DirectionCoordinate();
	velocity->x = mouse.x - this->position->x;
	velocity->y = mouse.y - this->position->y;
	velocity->Normalize();
	size = 10;
	attack = 1;
}


PlayerBullet::~PlayerBullet()
{

}

void PlayerBullet::Initialize()
{
}

void PlayerBullet::Update()
{
	float speed = 10;
	position->x += velocity->x * speed;
	position->y += velocity->y * speed;
	if ((0 > position->x ||
		0 > position->y ||
		Screen::WinWidth < position->x ||
		Screen::WinHight < position->y) ||
		hp <= 0)
	{
		isDead = true;
	}
}

void PlayerBullet::Hit(GameObject * obj)
{
	if (obj->GetType() == enemy)
	{
		obj->Damege(attack);
	}
	if (hp <= 0)
	{
		isDead = true;
	}
}

void PlayerBullet::Draw()
{
	Display::Instance()->SetScreen(PlayerBullet_Screen);
	DrawCircle(position->x, position->y, 5, GetColor(255, 255, 255), 0);
}
