#include "PlayerBullet.h"
#include "MousePointer.h"
#include "DxLib.h"

PlayerBullet::PlayerBullet(Vector2 *position)
	:GameObject(position,player_bullet,true)
{
	position = new Vector2(position->x, position->y);
	Vector2 mouse = MousePointer::Instance()->GetPosition();
	velocity->x = mouse.x - this->position->x;
	velocity->y = mouse.y - this->position->y;
	velocity->Normalize();
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
}

void PlayerBullet::Draw()
{
	DrawCircle(position->x, position->y, 5, GetColor(255, 255, 255), 0);
}
