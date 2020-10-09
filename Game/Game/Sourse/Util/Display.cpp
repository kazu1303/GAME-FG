#include "Display.h"
#include "Screen.h"
#include "DxLib.h"

Display* Display::instance = nullptr;

Display::Display()
{
	instance = this;
}


Display::~Display()
{
}

//�C���X�^���X��Ԃ�
Display * Display::Instance()
{
	return instance;
}

//�}�X�N�̐���
void Display::MakeDrawScreen()
{
	//enum�̐������X�N���[�����쐬
	for (int i = 0; i < screenNum; i++)
	{
		MakeDrawScreen((ScreenID)i, MakeScreen(Screen::WinWidth, Screen::WinHight, true));
	}
}

//�쐬�����X�N���[����map�ɕۑ�
void Display::MakeDrawScreen(ScreenID id, int screen)
{
	screens[id] = screen;
}

//�}�X�N�̕`��̃N���A
void Display::ClearScreen()
{
	ClearDrawScreen();
	for (int i = 0; i < screenNum; i++)
	{
		SetDrawScreen(screens[(ScreenID)i]);
		ClearDrawScreen();
	}
	SetDrawScreen(DX_SCREEN_BACK);
}

//�`�悷��}�X�N���Z�b�g
void Display::SetScreen(ScreenID id)
{
	SetDrawScreen(screens[id]);
}

//�S�}�X�N�̕`��
void Display::DrawScreen()
{
	SetDrawScreen(DX_SCREEN_BACK);
	DrawGraph(0, 0, screens[Block_Screen], true);
	DrawGraph(0, 0, screens[CloudofDust_Screen], true);
	DrawGraph(0, 0, screens[Item_Screen], true);
	DrawGraph(0, 0, screens[PlayerLeg_Screen], true);
	DrawGraph(0, 0, screens[Firing_Screen], true);
	DrawGraph(0, 0, screens[PlayerBullet_Screen], true);
	DrawGraph(0, 0, screens[PlayerHead_Screen], true);
	DrawGraph(0, 0, screens[BossLeg_Screen], true);
	DrawGraph(0, 0, screens[BossDust_Screen], true);
	DrawGraph(0, 0, screens[BossAttack_Screen], true);
	DrawGraph(0, 0, screens[BossHead_Screen], true);
	DrawGraph(0, 0, screens[Enemy_Screen], true);
	DrawGraph(0, 0, screens[Particle_Screen], true);
}