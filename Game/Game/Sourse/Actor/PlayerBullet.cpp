#include "PlayerBullet.h"
#include "MousePointer.h"
#include "DxLib.h"
#include "Screen.h"
#include "Display.h"
#include "Controller.h"

PlayerBullet::PlayerBullet(Vector2 *position, float radian)
	:GameObject(position,player_bullet,true)
{
	velocity->x = cos(radian);
	velocity->y = -sin(radian);
	velocity->Normalize();
	size = 20;
	attack = 1;
}


PlayerBullet::~PlayerBullet()
{

}

//初期化
void PlayerBullet::Initialize()
{
}

//毎フレーム処理
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

//ヒット時処理
void PlayerBullet::Hit(GameObject * obj)
{
	if (obj->GetType() == enemy ||
		obj->GetType() == enemy_bullet)
	{
		obj->Damege(attack);
	}
	if (hp <= 0)
	{
		isDead = true;
	}
}

//描画処理
void PlayerBullet::Draw()
{
	Display::Instance()->SetScreen(PlayerBullet_Screen);
	DrawCircle((int)(position->x), (int)(position->y), size / 2, GetColor(255, 255, 255), 0);
}
