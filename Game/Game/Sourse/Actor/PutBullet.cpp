#include "PutBullet.h"
#include "MousePointer.h"
#include "DxLib.h"
#include "Screen.h"
#include "Display.h"
#include "KeyBoard.h"
#include "Controller.h"

PutBullet::PutBullet(Vector2 *position)
	:GameObject(position, player_bullet, true)
{
	Vector2 mouse = Controller::Instance()->DirectionCoordinate();
	velocity->x = mouse.x - this->position->x;
	velocity->y = mouse.y - this->position->y;
	velocity->Normalize();
	size = 10;
	speed = 0.2f;
	attack = 1;
}


PutBullet::~PutBullet()
{
}

//初期化
void PutBullet::Initialize()
{
}

//毎フレーム処理
void PutBullet::Update()
{
	if (KeyBoard::Instance()->GetKeyTrigger(KEY_INPUT_SPACE) || Controller::Instance()->GetKey(PAD_INPUT_7))
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

//描画処理
void PutBullet::Draw()
{
	Display::Instance()->SetScreen(PlayerBullet_Screen);
	DrawCircle((int)(position->x), (int)(position->y), 5, GetColor(135, 206, 250), 0);
}

//ヒット時処理
void PutBullet::Hit(GameObject * obj)
{
	if (obj->GetType() == enemy ||
		obj->GetType() == enemy_bullet)
	{
		obj->Damege(attack);
	}
}

//ダメージ計算
void PutBullet::Damege(int attack)
{
	if (speed <= 1.0f)
	{
		hp -= attack;
		if (hp <= 0)
		{
			isDead = true;
		}
	}
}
