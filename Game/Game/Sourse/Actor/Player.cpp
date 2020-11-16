#include "Player.h"
#include "DxLib.h"
#include "MousePointer.h"
#include "PlayerBullet.h"
#include "PutBullet.h"
#include "SlowBullet.h"
#include "Util.h"
#include "DisPlay.h"
#include "Screen.h"
#include "KeyBoard.h"
#include "Clock.h"
#include "Controller.h"
#include "HealParticle.h"
#include "PlusBullet.h"


Player::Player(Vector2 *position)
	:GameObject(position, player, true, 10, 10)
{
	bulletTimer = Timer(0.1f, true);
	healTimer = Timer(3.0f, true);
	size = 60;
	putBulletNum = 10;
	slowBulletNum = 10;
	operation = false;
}


Player::~Player()
{
}

//ϊ»
void Player::Initialize()
{

}

//t[
void Player::Update()
{
	if (KeyBoard::GetKeyTrigger(KEY_INPUT_1))
	{
		operation = false;
	}
	if (KeyBoard::GetKeyTrigger(KEY_INPUT_2))
	{
		operation = true;
	}
	if (Clock::Instance().TimeZoneTrigger() && Clock::Instance().GetTimeZone() == morning)
	{
		int MaxBullet = 10;
		putBulletNum = MaxBullet;
		slowBulletNum = MaxBullet;
		healTimer.Reset();
		new PlusBullet(new Vector2(position->x, position->y));
	}
	if (operation)
	{
		angle = atan2(position->x - Controller::Instance()->DirectionCoordinate().x, position->y - Controller::Instance()->DirectionCoordinate().y) + Util::AngleToRadian(90);
	}
	else
	{
		angle = atan2(position->x - MousePointer::Instance()->GetPosition().x, position->y - MousePointer::Instance()->GetPosition().y) + Util::AngleToRadian(90);
	}

	Heal();
	Firing();
	FiringPutBullet();
	FiringSlowBullet();
	if (hp <= 0)
	{
		isDead = true;
	}

}

//`ζ
void Player::Draw()
{
	Display::Instance()->SetScreen(Player_Screen);
	DrawCircle((int)(position->x), (int)(position->y), size / 2, GetColor(255, 255, 255), 0);
	Display::Instance()->SetScreen(PlayerBattery_Screen);
	BatteryDraw();
	DrawDamageGauge();
	Display::Instance()->SetScreen(UI_Screen);
	BulletIcon(Vector2(632, 0), "ZR", "ΑκeP", GetColor(255, 255, 255), putBulletNum);
	BulletIcon(Vector2(700, 0), "X", "ΑκeQ", GetColor(255, 255, 255), slowBulletNum);
	//BulletIcon(Vector2(0, 700),"ZR", "", GetColor(135, 206, 250), maxPutBullet);
	//BulletIcon(Vector2(68, 700), "X", "", GetColor(255, 255, 255), maxSlowBullet);
}

//qbg
void Player::Hit(GameObject * obj)
{
	if (obj->GetType() == enemy ||
		obj->GetType() == enemy_bullet)
	{
		obj->Damege(500);
	}
}

//e­Λ
void Player::Firing()
{
	if (Controller::Instance()->GetKey(PAD_INPUT_4) || (GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		bulletTimer.Update();
		if (bulletTimer.IsTime())
		{
			//Sound::Instance()->PlaySE("firing");
			float r = 30;
			new PlayerBullet(new Vector2(position->x + r * cos(angle), position->y + r * -sin(angle)),angle);
		}
	}
	else
	{
		bulletTimer.Max();
	}
}

//PutBullet­Λ
void Player::FiringPutBullet()
{
	if (putBulletNum > 0 && ((KeyBoard::GetKeyTrigger(KEY_INPUT_Z) || Controller::Instance()->GetKey(PAD_INPUT_8))))
	{
		float r = 30;
		new PutBullet(new Vector2(position->x + r * cos(angle), position->y + r * -sin(angle)),angle);
		putBulletNum--;
	}
}

//SlowBullet­Λ
void Player::FiringSlowBullet()
{
	if (slowBulletNum > 0 && ((KeyBoard::GetKeyTrigger(KEY_INPUT_X) || Controller::Instance()->GetKey(PAD_INPUT_1))))
	{
		float r = 30;
		new SlowBullet(new Vector2(position->x + r * cos(angle), position->y + r * -sin(angle)),angle);
		slowBulletNum--;
	}
}

//CδΜ`ζ
void Player::BatteryDraw()
{
	DrawCircle((int)(position->x), (int)(position->y), size / 2 -15, GetColor(255, 255, 255), 1);
	//angle = atan2(position->x - MousePointer::Instance()->GetPosition().x , position->y - MousePointer::Instance()->GetPosition().y);
	float r = 40;
	//angle = angle * (180.0f / PI) + 90;
	float radian1 = angle + Util::AngleToRadian(25);
	float radian2 = angle - Util::AngleToRadian(25);
	DrawTriangle((int)(position->x), (int)(position->y), (int)(position->x + r * cos(radian1)), (int)(position->y + r * -sin(radian1)), (int)(position->x + r * cos(radian2)), (int)(position->y + r * -sin(radian2)), GetColor(255, 255, 255), 1);
}

//ΜΝQ[WΜ`ζ
void Player::DrawDamageGauge()
{
	if (hp < 0)
	{
		hp = 0;
	}
	Display::Instance()->SetScreen(UI_Screen);
	float gaugesizex = 248;
	int gaugesizey = 68;
	DrawBox((int)(Screen::WinWidth / 2 - gaugesizex), 0, (int)(Screen::WinWidth / 2 + gaugesizex), gaugesizey, GetColor(255, 255, 255), 1);
	float rate = hp / 10.0f;
	float currentGaugesizex = gaugesizex * 2 * rate;
	DrawBox((int)(Screen::WinWidth / 2 - gaugesizex), 0, (int)(Screen::WinWidth / 2 - gaugesizex + currentGaugesizex), gaugesizey, GetColor(0, 255, 127), 1);
}

//eACRΜ`ζ
void Player::BulletIcon(Vector2 pos, std::string key, std::string name, int Color, int num)
{
	int length = key.length();
	int charXsize = 10;
	int iconSize = 68;
	int centering = 2;
	DrawBox(pos.x, pos.y, pos.x + iconSize, pos.y + iconSize, GetColor(255, 255, 255), 0);
	DrawBox(pos.x, pos.y, pos.x + charXsize * length + centering, pos.y + iconSize / 4 + centering, GetColor(255, 255, 255), 0);
	DrawString(pos.x + centering, pos.y + centering, key.c_str(), GetColor(255, 255, 255));
	DrawString(pos.x + centering, pos.y + iconSize / 4 * 3, name.c_str(), GetColor(255, 255, 255));
	DrawCircle(pos.x + iconSize / 2, pos.y + iconSize / 2, 5, Color, 0);
	DrawString(pos.x + iconSize / 2 + 3, pos.y + iconSize / 2, "~", GetColor(255, 255, 255));
	//DrawString(pos.x + iconSize / 2 + 15, pos.y + iconSize / 2, std::to_string(num).c_str(), GetColor(255, 255, 255));
	DrawFormatString(pos.x + iconSize / 2 + 15, pos.y + iconSize / 2, GetColor(255, 255, 255), "%2d", num);
}
	
//ρ
void Player::Heal()
{
	if (Clock::Instance().GetTimeZone() == morning)
	{
		healTimer.Update();
		if (healTimer.IsTime())
		{
			hp++;
			if (hp > maxHp)
			{
				hp = maxHp;
			}
			new HealParticle(new Vector2(position->x, position->y), 30);
		}
	}
}
