#include "PutBullet.h"
#include "MousePointer.h"
#include "DxLib.h"
#include "Screen.h"
#include "Display.h"
#include "KeyBoard.h"

PutBullet::PutBullet(Vector2 *position)
	:GameObject(position, player_bullet, true)
{
	position = new Vector2(position->x, position->y);
	Vector2 mouse = MousePointer::Instance()->GetPosition();
	velocity->x = mouse.x - this->position->x;
	velocity->y = mouse.y - this->position->y;
	velocity->Normalize();
	size = 10;
	speed = 0.5f;
}


PutBullet::~PutBullet()
{
}

void PutBullet::Initialize()
{
}

void PutBullet::Update()
{
	if (KeyBoard::Instance()->GetKeyTrigger(KEY_INPUT_SPACE))
	{
		speed = 20;
	}

	position->x += velocity->x * speed;
	position->y += velocity->y * speed;
	if (0 > position->x ||
		0 > position->y ||
		Screen::WinWidth < position->x ||
		Screen::WinHight < position->y)
	{
		isDead = true;
	}
}

void PutBullet::Draw()
{
	Display::Instance()->SetScreen(PlayerBullet_Screen);
	DrawCircle(position->x, position->y, 5, GetColor(135, 206, 250), 0);
}
