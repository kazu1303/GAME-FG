#include "Player.h"
#include "DxLib.h"
#include "MousePointer.h"
#include "PlayerBullet.h"


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
}

void Player::Firing()
{
	//�e�̔���
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		bulletTimer.Update();
		//bullettimer��true�̎��e�̔��˂Ɖ��o
		if (bulletTimer.IsTime())
		{
			//Sound::Instance()->PlaySE("firing");
			new PlayerBullet(position);
		}
	}
	//�}�E�X��������ĂȂ��Ƃ������ɔ��˂ł���悤��
	else
	{
		bulletTimer.Max();
	}
}
