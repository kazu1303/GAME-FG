#include "PutBullet.h"
#include "MousePointer.h"
#include "DxLib.h"
#include "Screen.h"
#include "Display.h"
#include "KeyBoard.h"
#include "Controller.h"
#include "SceneManager.h"

PutBullet::PutBullet(Vector2 *position, float radian)
	:GameObject(position, player_bullet, true)
{
	velocity->x = cos(radian);
	velocity->y = -sin(radian);
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
	if (KeyBoard::Instance()->GetKeyTrigger(KEY_INPUT_SPACE) || Controller::Instance()->GetButtonTrigger(PAD_INPUT_7))
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
	if (speed <= 1.0f)
	{
		DrawIcon();
	}
}

//ヒット時処理
void PutBullet::Hit(GameObject * obj)
{
	if (obj->GetType() == enemy ||
		obj->GetType() == enemy_bullet)
	{
		if (speed <= 1.0f)
		{
			obj->Damege(attack);
		}
		else
		{
			float dead = 100;
			obj->Damege(dead);
		}
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

void PutBullet::DrawIcon()
{
	if (SceneManager::Instance()->CurrentScene() == title)
	{
		DrawBox(Screen::WinWidth / 2 - 64, Screen::WinHight / 2 + 108, Screen::WinWidth / 2 , Screen::WinHight / 2 + 108 + 20, GetColor(255, 255, 255), 0);
		DrawString(Screen::WinWidth / 2 - 64 + 24, Screen::WinHight / 2 + 110, "LT", GetColor(255, 255, 255));
	}
	else if (SceneManager::Instance()->CurrentScene() == gamePlay)
	{
		DrawBox(632, 68, 632 + 68, 68 + 20, GetColor(255, 255, 255), 0);
		DrawString(660, 70, "LT", GetColor(255, 255, 255));
	}
}
