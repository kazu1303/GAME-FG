#include "SlowBullet.h"
#include "DxLib.h"
#include "Display.h"
#include "SlowArea.h"
#include "Controller.h"


SlowBullet::SlowBullet(Vector2 *position, float radian)
	:GameObject(position,slow_bullet,true)
{
	velocity->x = cos(radian);
	velocity->y = -sin(radian);
	velocity->Normalize();
	size = 10;
	attack = 0;
	deadTimer = Timer(0.5f, false);
}


SlowBullet::~SlowBullet()
{
}

//‰Šú‰»
void SlowBullet::Initialize()
{
}

//–ˆƒtƒŒ[ƒ€ˆ—
void SlowBullet::Update()
{
	deadTimer.Update();
	float speed = 10;
	position->x += velocity->x * speed;
	position->y += velocity->y * speed;
	if (deadTimer.IsTime())
	{
		isDead = true;
		new SlowArea(new Vector2(position->x, position->y));
	}
}

//•`‰æˆ—
void SlowBullet::Draw()
{
	Display::Instance()->SetScreen(PlayerBullet_Screen);
	DrawCircle((int)(position->x), (int)(position->y), 5, GetColor(255, 255, 255), 0);
}

//ƒqƒbƒgŽžˆ—
void SlowBullet::Hit(GameObject * obj)
{
	if (obj->GetType() == enemy)
	{
		isDead = true;
		new SlowArea(new Vector2(position->x,position->y));
	}
}
