#include "SlowBullet.h"
#include "DxLib.h"
#include "Display.h"
#include "MousePointer.h"
#include "Screen.h"
#include "SlowArea.h"



SlowBullet::SlowBullet(Vector2 *position)
	:GameObject(position,slow_bullet,true)
{
	destination = MousePointer::Instance()->GetPosition();
	velocity->x = destination.x - this->position->x;
	velocity->y = destination.y - this->position->y;
	velocity->Normalize();
	size = 10;
	attack = 0;
}


SlowBullet::~SlowBullet()
{
}

void SlowBullet::Initialize()
{
}

void SlowBullet::Update()
{
	float speed = 10;
	position->x += velocity->x * speed;
	position->y += velocity->y * speed;
	if (abs(position->x - destination.x) <= 5.0f &&
		abs(position->y - destination.y) <= 5.0f)
	{
		isDead = true;
		new SlowArea(position);
	}
	if (0 > position->x ||
		0 > position->y ||
		Screen::WinWidth < position->x ||
		Screen::WinHight < position->y)
	{
		isDead = true;
	}
}

void SlowBullet::Draw()
{
	Display::Instance()->SetScreen(PlayerBullet_Screen);
	DrawCircle(position->x, position->y, 5, GetColor(255, 255, 255), 0);
}

void SlowBullet::Hit(GameObject * obj)
{
	if (obj->GetType() == enemy)
	{
		isDead = true;
		new SlowArea(position);
	}
}
