#include "Title.h"

#include "Vector2.h"
#include "KeyBoard.h"
#include "DxLib.h"
#include "Sound.h"
#include "Renderer.h"
#include "MousePointer.h"
#include "Controller.h"
#include "Player.h" 
#include "Clock.h" 
#include "TitleEnemy.h" 
#include "Screen.h" 
#include "Util.h" 
#include "Display.h" 
#include "Font.h"



Title::Title()
{
	isEnd = false;
	gameObjectManager = new GameObjectManager();
	particleManager = new ParticleManager();
	buttonFont = CreateFontToHandle(NULL, 50, -1);
}

Title::~Title()
{
}

//初期化処理
void Title::Initialize()
{
	tutorial = B;
	isEnd = false;
	GameObjectManager::Instance()->Initialize();
	ParticleManager::Instance()->Initialize();
	Sound::Instance()->PlayBGM("title.mp3");
	new Player(new Vector2((float)(Screen::WinWidth / 2), (float)(Screen::WinHight / 2)));
	new Clock(new Vector2(40.0f, 40.0f));
	titleEnemyTimer = Timer(1.0f, true);
	tutorialTimer = Timer(0.5f,false);
}

//毎フレーム処理
void Title::Update()
{
	ParticleManager::Instance()->Update();
	GameObjectManager::Instance()->Update();
	titleEnemyTimer.Update();
	if (titleEnemyTimer.IsTime())
	{
		float angle = (float)(GetRand(360));
		float radian = Util::AngleToRadian(angle);
		float spawnLength = (float)Screen::WinWidth / 1.7f;
		Vector2 spawnPoint = Vector2((sin(radian) * spawnLength) + (Screen::WinWidth / 2), (cos(radian) * spawnLength) + (Screen::WinHight / 2));

		if (Clock::Instance().GetTimeZone() == morning)
		{
			new TitleEnemy(new Vector2(spawnPoint.x, spawnPoint.y));
		}
		else if (Clock::Instance().GetTimeZone() == night)
		{
			new TitleEnemy(new Vector2(spawnPoint.x, spawnPoint.y));
		}
	}
	switch (tutorial)
	{
	case B:
		if (Controller::Instance()->GetButtonTrigger(PAD_INPUT_4))
		{
			Sound::Instance()->PlaySE("success");
			tutorial++;
		}
		//if (KeyBoard::Instance()->GetKeyTrigger(KEY_INPUT_RETURN))tutorial++;
		break;
	case Y:
		if (Controller::Instance()->GetButtonTrigger(PAD_INPUT_2))
		{
			Sound::Instance()->PlaySE("success");
			tutorial++;
		}
		//if (KeyBoard::Instance()->GetKeyTrigger(KEY_INPUT_Z))tutorial++;
		break;
	case RT:
		if (Controller::Instance()->GetButtonTrigger(PAD_INPUT_8))
		{
			Sound::Instance()->PlaySE("success");
			tutorial++;
		}
		//if (KeyBoard::Instance()->GetKeyTrigger(KEY_INPUT_X))tutorial++;
		break;
	case LT:
		if (Controller::Instance()->GetButtonTrigger(PAD_INPUT_7))
		{
			Sound::Instance()->PlaySE("success");
			tutorial++;
		}
		//if (KeyBoard::Instance()->GetKeyTrigger(KEY_INPUT_C))tutorial++;
		break;
	case END:
		if (Controller::Instance()->GetButtonTrigger(PAD_INPUT_12))
		{
			Sound::Instance()->PlaySE("decide");
			isEnd = true;
		}
	default:
		break;
	}
}

//描画処理
void Title::Draw()
{
	GameObjectManager::Instance()->Draw();
	ParticleManager::Instance()->Draw();
	Display::Instance()->SetScreen(UI_Screen);
	DrawStringToHandle(220, 100, "TimeBullet", GetColor(255, 255, 255), Font::pixelM64);
	DrawStringToHandle(Screen::WinWidth / 2 - 272, Screen::WinHight / 2 - 100, "左スティックで砲塔の回転ができます", GetColor(255, 255, 255), Font::pixelM32);
	switch (tutorial)
	{
	case B:
		DrawStringToHandle(Screen::WinWidth / 2 - 176, Screen::WinHight / 2 + 130, "Bで弾の発射ができます", GetColor(255, 255, 255), Font::pixelM32);
		DrawCircle(Screen::WinWidth / 2, Screen::WinHight / 2 + 250, 30, GetColor(255, 0, 0));
		DrawStringToHandle(Screen::WinWidth / 2 - 13, Screen::WinHight / 2 + 225, "B", GetColor(255, 255, 255),buttonFont);
		break;
	case Y:
		DrawStringToHandle(Screen::WinWidth / 2 - 288, Screen::WinHight / 2 + 130, "Yで敵を遅くするエリアを発生させます", GetColor(255, 255, 255), Font::pixelM32);
		DrawCircle(Screen::WinWidth / 2, Screen::WinHight / 2 + 250, 30, GetColor(255, 255, 0));
		DrawStringToHandle(Screen::WinWidth / 2 - 13, Screen::WinHight / 2 + 225, "Y", GetColor(255, 255, 255), buttonFont);
		break;
	case RT:
		DrawStringToHandle(Screen::WinWidth / 2 - 160, Screen::WinHight / 2 + 130, "RTで貫通弾を発射して", GetColor(255, 255, 255),Font::pixelM32);
		DrawBox(Screen::WinWidth / 2 - 30, Screen::WinHight / 2 + 225, Screen::WinWidth / 2 + 30, Screen::WinHight / 2 + 275, GetColor(255, 255, 255),FALSE);
		DrawStringToHandle(Screen::WinWidth / 2 - 25, Screen::WinHight / 2 + 225, "RT", GetColor(255, 255, 255), buttonFont);
		break;
	case LT:
		DrawStringToHandle(Screen::WinWidth / 2 - 224, Screen::WinHight / 2 + 130, "LTで貫通弾の加速ができます", GetColor(255, 255, 255),Font::pixelM32);
		DrawBox(Screen::WinWidth / 2 - 30, Screen::WinHight / 2 + 225, Screen::WinWidth / 2 + 30, Screen::WinHight / 2 + 275, GetColor(255, 255, 255), FALSE);
		DrawStringToHandle(Screen::WinWidth / 2 - 25, Screen::WinHight / 2 + 225, "LT", GetColor(255, 255, 255), buttonFont);
		break;
	case END:
		DrawStringToHandle(Screen::WinWidth / 2 - 80, Screen::WinHight / 2 + 225, "PUSH START", GetColor(255, 255, 255), Font::pixelM32);

		break;
	default:
		break;
	}
	MousePointer::Instance()->Draw();
}

//次のシーン
Scene Title::Next()
{
	Sound::Instance()->StopBGM();
	return gamePlay;
}

//現在のシーン
Scene Title::CurrentScene()
{
	return title;
}
