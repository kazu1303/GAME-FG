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

//インスタンスを返す
Display * Display::Instance()
{
	return instance;
}

//マスクの生成
void Display::MakeDrawScreen()
{
	//enumの数だけスクリーンを作成
	for (int i = 0; i < screenNum; i++)
	{
		MakeDrawScreen((ScreenID)i, MakeScreen(Screen::WinWidth, Screen::WinHight, true));
	}
}

//作成したスクリーンをmapに保存
void Display::MakeDrawScreen(ScreenID id, int screen)
{
	screens[id] = screen;
}

//マスクの描画のクリア
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

//描画するマスクをセット
void Display::SetScreen(ScreenID id)
{
	SetDrawScreen(screens[id]);
}

//全マスクの描画
void Display::DrawScreen()
{
	SetDrawScreen(DX_SCREEN_BACK);
	DrawGraph(0, 0, screens[Player_Screen], true);
	DrawGraph(0, 0, screens[PlayerBullet_Screen], true);
	DrawGraph(0, 0, screens[PlayerBattery_Screen], true);
	DrawGraph(0, 0, screens[Enemy_Screen], true);
	DrawGraph(0, 0, screens[SkyColor_Screen], true);	
	DrawGraph(0, 0, screens[Particle_Screen], true);
	DrawGraph(0, 0, screens[UI_Screen], true);
}
