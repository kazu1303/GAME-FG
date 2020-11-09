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


Player::Player(Vector2 *position)
	:GameObject(position,player,true,10,10)
{
	position = new Vector2(position->x, position->y);
	bulletTimer = Timer(0.3f, true);
	healTimer = Timer(3.0f, true);
	size = 40;
}


Player::~Player()
{
}

void Player::Initialize()
{

}

void Player::Update()
{
	if (Clock::Instance().TimeZoneTrigger() && Clock::Instance().GetTimeZone() == morning)
	{
		maxPutBullet = 10;
		maxSlowBullet = 10;
		healTimer.Reset();
	}
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
		}
	}
	angle = atan2(position->x - Controller::Instance()->DirectionCoordinate().x, position->y - Controller::Instance()->DirectionCoordinate().y);
	Firing();
	FiringPutBullet();
	FiringSlowBullet();
	if (hp <= 0)
	{
		isDead = true;
	}

}

void Player::Draw()
{
	Display::Instance()->SetScreen(Player_Screen);
	DrawCircle(position->x, position->y, 20, GetColor(255, 255, 255), 0);
	Display::Instance()->SetScreen(PlayerBattery_Screen);
	BatteryDraw();
	DrawDamageGauge();
	Display::Instance()->SetScreen(UI_Screen);
	BulletIcon(Vector2(34, 734),"X", "特殊弾１", GetColor(135, 206, 250), maxPutBullet);
	BulletIcon(Vector2(102, 734), "Y", "特殊弾2", GetColor(255, 255, 255), maxSlowBullet);
}

void Player::Hit(GameObject * obj)
{
	if (obj->GetType() == enemy ||
		obj->GetType() == enemy_bullet)
	{
		obj->Damege(500);
	}
}

void Player::Firing()
{
	//弾の発射
	if (Controller::Instance()->GetKey(PAD_INPUT_4))
	{
		bulletTimer.Update();
		//bullettimerがtrueの時弾の発射と演出
		if (bulletTimer.IsTime())
		{
			//Sound::Instance()->PlaySE("firing");
			float r = 30;
			new PlayerBullet(new Vector2(position->x + r * cos(angle + Util::AngleToRadian(90)), position->y + r * -sin(angle + Util::AngleToRadian(90))));
		}
	}
	//マウスが押されてないときすぐに発射できるように
	else
	{
		bulletTimer.Max();
	}
}

void Player::FiringPutBullet()
{
	if (maxPutBullet > 0 && ((KeyBoard::GetKeyTrigger(KEY_INPUT_Z) || Controller::Instance()->GetKey(PAD_INPUT_1))))
	{
		float r = 30;
		new PutBullet(new Vector2(position->x + r * cos(angle + Util::AngleToRadian(90)), position->y + r * -sin(angle + Util::AngleToRadian(90))));
		maxPutBullet--;
	}
}

void Player::FiringSlowBullet()
{
	if (maxSlowBullet > 0 && ((KeyBoard::GetKeyTrigger(KEY_INPUT_X) || Controller::Instance()->GetKey(PAD_INPUT_2))))
	{
		float r = 30;
		new SlowBullet(new Vector2(position->x + r * cos(angle + Util::AngleToRadian(90)), position->y + r * -sin(angle + Util::AngleToRadian(90))));
		maxSlowBullet--;
	}
}

void Player::BatteryDraw()
{
	DrawCircle(position->x, position->y, 10, GetColor(255, 255, 255), 1);
	//angle = atan2(position->x - MousePointer::Instance()->GetPosition().x , position->y - MousePointer::Instance()->GetPosition().y);
	float r = 30;
	angle = angle * (180.0f / PI) + 90;
	float radian1 = Util::AngleToRadian(angle + 25);
	float radian2 = Util::AngleToRadian(angle - 25);
	DrawTriangle(position->x, position->y, position->x + r * cos(radian1), position->y + r * -sin(radian1), position->x + r * cos(radian2), position->y + r * -sin(radian2), GetColor(255, 255, 255), 1);
}

//HPゲージの描画
void Player::DrawDamageGauge()
{
	if (hp < 0)
	{
		hp = 0;
	}
	Display::Instance()->SetScreen(UI_Screen);
	//最大の体力ゲージの描画
	float gaugesizex = 300;
	int gaugesizey = 50;
	DrawBox((int)(Screen::WinWidth / 2 - gaugesizex), 0, (int)(Screen::WinWidth / 2 + gaugesizex), gaugesizey, GetColor(255, 255, 255), 1);
	//現在の体力ゲージの描画
	float rate = hp / 10.0f;
	float currentGaugesizex = gaugesizex * 2 * rate;
	DrawBox((int)(Screen::WinWidth / 2 - gaugesizex), 0, (int)(Screen::WinWidth / 2 - gaugesizex + currentGaugesizex), gaugesizey, GetColor(0, 255, 127), 1);
}

void Player::BulletIcon(Vector2 pos, const char* key,const char * name, int Color, int num)
{
	int iconSize = 68;
	DrawBox(pos.x- iconSize / 2, pos.y - iconSize / 2, pos.x+ iconSize / 2, pos.y + iconSize / 2, GetColor(255,255,255), 0);
	DrawBox(pos.x - iconSize / 2, pos.y - iconSize / 2, pos.x - 17, pos.y - 17, GetColor(255, 255, 255), 0);
	DrawString(pos.x - 30, pos.y - iconSize / 2, key, GetColor(255, 255, 255));
	DrawString(pos.x - iconSize / 2, pos.y + 19, name, GetColor(255, 255, 255));
	DrawCircle(pos.x, pos.y, 5, Color, 0);
	DrawString(pos.x + 3, pos.y + 3, "×", GetColor(255, 255, 255));
	DrawString(pos.x + 15, pos.y + 3, std::to_string(num).c_str(), GetColor(255, 255, 255));
}
