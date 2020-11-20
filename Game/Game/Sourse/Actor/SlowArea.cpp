#include "SlowArea.h"
#include "DxLib.h"
#include "Display.h"
#include "Screen.h"


SlowArea::SlowArea(Vector2 *position)
	:GameObject(position,slow_area,true)
{
	deadTimer = Timer(6.0f, false);
	size = 0;
}


SlowArea::~SlowArea()
{
}

//������
void SlowArea::Initialize()
{
}

//���t���[������
void SlowArea::Update()
{
	if (size < 550)
	{
		size += 10;
	}
	deadTimer.Update();
	if (deadTimer.IsTime())
	{
		isDead = true;
	}
}

//�`�揈��
void SlowArea::Draw()
{
	Display::Instance()->SetScreen(PlayerBullet_Screen);
	DrawCircle((int)(position->x), (int)(position->y), size / 2, GetColor(255, 255, 255), 0);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
	DrawCircle((int)(position->x), (int)(position->y), size / 2, GetColor(255, 255, 255), 1);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//�q�b�g������
void SlowArea::Hit(GameObject * obj)
{
	if (obj->GetType() == enemy)
	{
		obj->SpeedDown(5.0f);
	}
}
