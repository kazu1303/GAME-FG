#include "GameOver.h"
#include "Screen.h"
#include "DxLib.h"
//#include "Renderer.h"
#include "KeyBoard.h"
#include "Controller.h"
#include "GameObjectManager.h"
#include "Clock.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Util.h"
#include "Font.h"

GameOver::GameOver()
{
	enemy1Summon = Timer(3.5f, true);
	enemy2Summon = Timer(6.5f, true);
	enemy3Summon = Timer(8.0f, true);
}


GameOver::~GameOver()
{
}

//初期化処理
void GameOver::Initialize()
{
	isEnd = false;
}

//毎フレーム処理
void GameOver::Update()
{
	//次のシーンへの変更処理
	if (Controller::Instance()->GetButtonTrigger(PAD_INPUT_4) || Controller::Instance()->GetButtonTrigger(PAD_INPUT_3) || KeyBoard::GetKeyTrigger(KEY_INPUT_RETURN))
	{
		isEnd = true;
	}
	enemy1Summon.Update();
	enemy2Summon.Update();
	enemy3Summon.Update();

	//敵の生成
	if (enemy1Summon.IsTime())
	{
		//敵が出現する方向を決める
		float angle = (float)(GetRand(360));
		float radian = Util::AngleToRadian(angle);
		float spawnLength = (float)Screen::WinWidth / 1.7f;
		Vector2 spawnPoint = Vector2((sin(radian) * spawnLength) + (Screen::WinWidth / 2), (cos(radian) * spawnLength) + (Screen::WinHight / 2));

		if (Clock::Instance().GetTimeZone() == morning)
		{
			new Enemy1(new Vector2(spawnPoint.x, spawnPoint.y), 1);
		}
		else if (Clock::Instance().GetTimeZone() == night)
		{
			new Enemy1(new Vector2(spawnPoint.x, spawnPoint.y), 2);
		}
	}
	if (enemy2Summon.IsTime())
	{
		//敵が出現する方向を決める
		float angle = (float)(GetRand(360));
		float radian = Util::AngleToRadian(angle);
		float spawnLength = (float)Screen::WinWidth / 1.7f;
		Vector2 spawnPoint = Vector2((sin(radian) * spawnLength) + (Screen::WinWidth / 2), (cos(radian) * spawnLength) + (Screen::WinHight / 2));

		if (Clock::Instance().GetTimeZone() == morning)
		{
			new Enemy2(new Vector2(spawnPoint.x, spawnPoint.y), 1);
		}
		else if (Clock::Instance().GetTimeZone() == night)
		{
			new Enemy2(new Vector2(spawnPoint.x, spawnPoint.y), 1);
		}
	}
	//敵の生成
	if (enemy3Summon.IsTime())
	{
		//敵が出現する方向を決める
		float angle = (float)(GetRand(360));
		float radian = Util::AngleToRadian(angle);
		float spawnLength = (float)Screen::WinWidth / 1.7f;
		Vector2 spawnPoint = Vector2((sin(radian) * spawnLength) + (Screen::WinWidth / 2), (cos(radian) * spawnLength) + (Screen::WinHight / 2));

		if (Clock::Instance().GetTimeZone() == morning)
		{
			new Enemy3(new Vector2(spawnPoint.x, spawnPoint.y), 2);
		}
		else if (Clock::Instance().GetTimeZone() == night)
		{
			new Enemy3(new Vector2(spawnPoint.x, spawnPoint.y), 4);
		}
	}
	GameObjectManager::Instance()->Update();
}

//描画処理
void GameOver::Draw()
{
	//Renderer::Instance()->DrawTexture1("gameover", new Vector2((float)(Screen::WinWidth / 2.0f), (float)(Screen::WinHight / 2.0f)), 0.0f, 6.0f);
	//Renderer::Instance()->DrawTexture1("enter", new Vector2((float)(Screen::WinWidth / 2.0f), (float)(Screen::WinHight - 200.0f)), 0);
	GameObjectManager::Instance()->Draw();
	DrawStringToHandle(300, 400, "GameOver", GetColor(255, 255, 255),Font::pixelM64);
	//DrawString(330, 330, "Press Enter", GetColor(255, 255, 255));
	DrawCircle(153, 707, 10, GetColor(0, 255, 0));
	DrawString(150, 700, "A", GetColor(255, 255, 255));
	DrawStringToHandle(200, 700, "タイトル", GetColor(255, 255, 255),Font::pixelM16);
	DrawCircle(403, 707, 10, GetColor(255, 0, 0));
	DrawString(400, 700, "B", GetColor(255, 255, 255));
	DrawStringToHandle(450, 700, "リトライ", GetColor(255, 255, 255),Font::pixelM16);
}

//次のシーン
Scene GameOver::Next()
{
	if (Controller::Instance()->GetButtonTrigger(PAD_INPUT_4))
	{
		return gamePlay;
	}
	return title;
}

//現在のシーン
Scene GameOver::CurrentScene()
{
	return gameOver;
}
