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
#include "SlowArea.h"
#include "DeadParticle.h"
#include "SceneManager.h"
#include "Sound.h"


Player::Player(Vector2 *position)
	:GameObject(position, player, true, 10, 10)
{
	bulletTimer = Timer(0.1f, true);
	healTimer = Timer(3.0f, true);
	damegeTimer = Timer(1.0f,false);
	deadTimer = Timer(2.0f, false);
	quakeTimer = Timer(0.01f, true);
	damegeTimer.Max();
	size = 60;
	putBulletNum = 10;
	slowBulletNum = 1;
	operation = true;
	velocity->x = 1;
}


Player::~Player()
{
}

//‰Šú‰»
void Player::Initialize()
{

}

//–ˆƒtƒŒ[ƒ€ˆ—
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
	if (SceneManager::Instance()->CurrentScene() == title)
	{
		int MaxBullet = 10;
		putBulletNum = MaxBullet;
		slowBulletNum = 1;
	}
	if (Clock::Instance().TimeZoneTrigger() && Clock::Instance().GetTimeZone() == morning)
	{
		int MaxBullet = 10;

		putBulletNum = MaxBullet;
		slowBulletNum = 1;
		Sound::Instance()->PlaySE("decision49");
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
	if (hp > 0)
	{
		if (SceneManager::Instance()->CurrentScene() == gamePlay)
		{
			Heal();
		}
		Firing();
		FiringPutBullet();
		FiringSlowBullet();
	}
	else
	{
		DrawDead();
	}

	if (isDead)
	{

	}
	if (!damegeTimer.IsTime())
	{
		damegeTimer.Update();
	}
}

//•`‰æˆ—
void Player::Draw()
{
	Display::Instance()->SetScreen(Player_Screen);
	if (!damegeTimer.IsTime())
	{
		SetDrawBlendMode(DX_BLENDMODE_ADD, 160);
		DrawCircle((int)(position->x), (int)(position->y), size / 2, GetColor(255, 0, 0), 1);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
	}
	DrawCircle((int)(position->x), (int)(position->y), size / 2, GetColor(255, 255, 255), 0);

	Display::Instance()->SetScreen(PlayerBattery_Screen);
	BatteryDraw();
	if (SceneManager::Instance()->CurrentScene() == gamePlay)
	{
		Display::Instance()->SetScreen(UI_Screen);
		DrawDamageGauge();
		BulletIcon(Vector2(632, 0), "RT", "ŠÑ’Ê’e", GetColor(255, 255, 255), putBulletNum);
		BulletIcon(Vector2(700, 0), "Y", "’x”ÍˆÍ", GetColor(255, 255, 255), slowBulletNum);
	}
	if (SceneManager::Instance()->CurrentScene() == title)
	{
		Display::Instance()->SetScreen(UI_Screen);
		BulletIcon(Vector2(Screen::WinWidth / 2- 64, Screen::WinHight / 2 + 40), "RT", "ŠÑ’Ê’e", GetColor(255, 255, 255), putBulletNum);
		BulletIcon(Vector2(Screen::WinWidth / 2, Screen::WinHight / 2 + 40), "X", "’x”ÍˆÍ", GetColor(255, 255, 255), slowBulletNum);
	}

	//BulletIcon(Vector2(0, 700),"ZR", "", GetColor(135, 206, 250), maxPutBullet);
	//BulletIcon(Vector2(68, 700), "X", "", GetColor(255, 255, 255), maxSlowBullet);
}

//ƒqƒbƒgˆ—
void Player::Hit(GameObject * obj)
{
	if (obj->GetType() == enemy ||
		obj->GetType() == enemy_bullet)
	{
		obj->Damege(500);
		if (!Sound::Instance()->CkeckSEPlay("punch-stop1"))
		{
			Sound::Instance()->PlaySE("punch-stop1");
		}
		damegeTimer.Reset();
		if (damegeTimer.IsTime())
		{
			damegeTimer.Update();
		}

	}
}

//’e”­Ëˆ—
void Player::Firing()
{
	if (Controller::Instance()->GetButton(PAD_INPUT_4) || (GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		bulletTimer.Update();
		if (bulletTimer.IsTime())
		{
			Sound::Instance()->PlaySE("gun");
			float r = 30;
			new PlayerBullet(new Vector2(position->x + r * cos(angle), position->y + r * -sin(angle)),angle);
		}
	}
	else
	{
		bulletTimer.Max();
	}
}

//PutBullet”­Ëˆ—
void Player::FiringPutBullet()
{
	if (putBulletNum > 0 && ((KeyBoard::GetKeyTrigger(KEY_INPUT_Z) || Controller::Instance()->GetButtonTrigger(PAD_INPUT_8))))
	{
		Sound::Instance()->PlaySE("put_short");
		float r = 30;
		new PutBullet(new Vector2(position->x + r * cos(angle), position->y + r * -sin(angle)),angle);
		putBulletNum--;
	}
}

//SlowBullet”­Ëˆ—
void Player::FiringSlowBullet()
{
	if (slowBulletNum > 0 && ((KeyBoard::GetKeyTrigger(KEY_INPUT_X) || Controller::Instance()->GetButtonTrigger(PAD_INPUT_2))))
	{
		Sound::Instance()->PlaySE("slow");
		float r = 30;
		new SlowArea(new Vector2(position->x, position->y));
		slowBulletNum--;
	}
}

//–C‘ä‚Ì•`‰æ
void Player::BatteryDraw()
{
	DrawCircle((int)(position->x), (int)(position->y), size / 2 -15, GetColor(255, 255, 255), 1);
	//angle = atan2(position->x - MousePointer::Instance()->GetPosition().x , position->y - MousePointer::Instance()->GetPosition().y);
	float r = 40;
	//angle = angle * (180.0f / PI) + 90;
	float radian1 = angle + Util::AngleToRadian(25);
	float radian2 = angle - Util::AngleToRadian(25);
	DrawTriangle((int)(position->x), (int)(position->y), (int)(position->x + r * cos(radian1)), (int)(position->y + r * -sin(radian1)), (int)(position->x + r * cos(radian2)), (int)(position->y + r * -sin(radian2)), GetColor(255, 255, 255), 1);
	r = 25;
	//int f = GetFontSize();
	//DrawLine(position->x, position->y, (int)(position->x + (r) * cos(angle)), (int)(position->y + (r) * -sin(angle)), GetColor(255, 0, 0));
	/*if (SceneManager::Instance()->CurrentScene() == title)
	{
		DrawCircle((int)((position->x + r * cos(angle))), (int)((position->y + r * -sin(angle))), 8, GetColor(255, 0, 0));
		DrawString((int)((position->x + r * cos(angle)) - 4), (int)((position->y + r * -sin(angle)) - 8), "B", GetColor(255, 255, 255));
	}*/
}

//‘Ì—ÍƒQ[ƒW‚Ì•`‰æ
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

//’eƒAƒCƒRƒ“‚Ì•`‰æ
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
	
//‰ñ•œˆ—
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
			Sound::Instance()->PlaySE("magic-cure4");
		}
	}
}

void Player::DrawDead()
{
	deadTimer.Update();
	quakeTimer.Update();
	if (deadTimer.IsTime())
	{
		isDead = true;
	}
	if (quakeTimer.IsTime())
	{
		velocity->x *= -1;
	}
	for (int i = 0; i < 5; i++)
	{
		new DeadParticle(new Vector2(position->x, position->y));
	}
	position->x += velocity->x;
	if (!Sound::Instance()->CkeckSEPlay("explode2"))
	{
		Sound::Instance()->PlaySE("explode2");
	}
	//Sound::Instance()->PlaySE("explode2");
}

int Player::GetHp()
{
	return hp;
}
