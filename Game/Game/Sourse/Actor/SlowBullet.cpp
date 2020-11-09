#include "SlowBullet.h"
#include "DxLib.h"
#include "Display.h"
#include "MousePointer.h"
#include "Screen.h"
#include "SlowArea.h"
#include "Controller.h"


SlowBullet::SlowBullet(Vector2 *position)
	:GameObject(position,slow_bullet,true)
{
	Vector2 mouse = Controller::Instance()->DirectionCoordinate();
	velocity->x = mouse.x - this->position->x;
	velocity->y = mouse.y - this->position->y;
	velocity->Normalize();
	size = 10;
	attack = 0;
	deadTimer = Timer(0.5f, false);
}


SlowBullet::~SlowBullet()
{
}

void SlowBullet::Initialize()
{
}

void SlowBullet::Update()
{
	deadTimer.Update();
	float speed = 10;
	position->x += velocity->x * speed;
	position->y += velocity->y * speed;
	if (deadTimer.IsTime())
	{
		isDead = true;
		new SlowArea(position);
	}
}

void SlowBullet::Draw()
{
	Display::Instance()->SetScreen(PlayerBullet_Screen);
	DrawCircle((int)(position->x), (int)(position->y), 5, GetColor(255, 255, 255), 0);
}

void SlowBullet::Hit(GameObject * obj)
{
	if (obj->GetType() == enemy)
	{
		isDead = true;
		new SlowArea(position);
	}
}
