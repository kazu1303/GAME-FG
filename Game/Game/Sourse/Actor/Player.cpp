#include "Player.h"
#include "DxLib.h"
#include "MousePointer.h"
#include "PlayerBullet.h"
#include "Util.h"


Player::Player(Vector2 *position)
	:GameObject(position,player,true,10,10)
{
	position = new Vector2(position->x, position->y);
	bulletTimer = Timer(0.5f, true);
}


Player::~Player()
{
}

void Player::Initialize()
{

}

void Player::Update()
{
	Firing();
}

void Player::Draw()
{
	DrawCircle(position->x, position->y, 20, GetColor(0, 0, 0), 0);
	BatteryDraw();
}

void Player::Firing()
{
	//’e‚Ì”­ŽË
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		bulletTimer.Update();
		//bullettimer‚ªtrue‚ÌŽž’e‚Ì”­ŽË‚Æ‰‰o
		if (bulletTimer.IsTime())
		{
			//Sound::Instance()->PlaySE("firing");
			new PlayerBullet(position);
		}
	}
	//ƒ}ƒEƒX‚ª‰Ÿ‚³‚ê‚Ä‚È‚¢‚Æ‚«‚·‚®‚É”­ŽË‚Å‚«‚é‚æ‚¤‚É
	else
	{
		bulletTimer.Max();
	}
}

void Player::BatteryDraw()
{
	DrawCircle(position->x, position->y, 10, GetColor(0, 0, 0), 1);
	angle = atan2(position->x - MousePointer::Instance()->GetPosition().x , position->y - MousePointer::Instance()->GetPosition().y);
	float r = 30;
	angle = angle * (180.0f / PI) + 90;
	float radian1 = Util::AngleToRadian(angle + 25);
	float radian2 = Util::AngleToRadian(angle - 25);
	//‚à‚µnull‚Å‚È‚¢‚È‚çŽ©•ª‚Ì•Ï”‚É‘ã“ü‚·‚é
	DrawTriangle(position->x, position->y, position->x + r * cos(radian1), position->y + r * -sin(radian1), position->x + r * cos(radian2), position->y + r * -sin(radian2), GetColor(0, 0, 0), 1);
}
