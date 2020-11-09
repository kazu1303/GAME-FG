#include "GamePlay.h"
#include"DxLib.h"
#include "KeyBoard.h"
#include "Player.h"
#include "Screen.h"
#include "GameObjectManager.h"
#include "MousePointer.h"
#include "Util.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Clock.h"



GamePlay::GamePlay()
{

}

GamePlay::~GamePlay()
{
}

//初期化処理
void GamePlay::Initialize()
{
	isEnd = false;
	enemy1Summon = Timer(0.8f, true);
	enemy2Summon = Timer(1.5f, true);
	enemy3Summon = Timer(2.0f, true);
	player = new Player(new Vector2((float)(Screen::WinWidth / 2), (float)(Screen::WinHight / 2)));
	new Clock(new Vector2(40.0f, 40.0f));
}

//毎フレーム処理
void GamePlay::Update()
{
	//次のシーンへの変更処理
	if (player->IsDead())
	{
		isEnd = true;
	}
	if (Clock::Instance().GetElapsedTime() >= 2)
	{
		isEnd = true;
	}

	GameObjectManager::Instance()->Update();
	if (Clock::Instance().GetElapsedTime() == 0)
	{
		if (Clock::Instance().TimeZoneTrigger() && Clock::Instance().GetTimeZone() == night)
		{
			enemy1Summon.Resetting(0.8f);
		}
		else if (Clock::Instance().TimeZoneTrigger() && Clock::Instance().GetTimeZone() == morning)
		{
			enemy1Summon.Resetting(0.6f);
		}
	}
	if (Clock::Instance().GetElapsedTime() == 1)
	{
		if (Clock::Instance().TimeZoneTrigger() && Clock::Instance().GetTimeZone() == night)
		{
			enemy1Summon.Resetting(1.5f);
		}
		else if (Clock::Instance().TimeZoneTrigger() && Clock::Instance().GetTimeZone() == morning)
		{
			enemy1Summon.Resetting(1.2f);
		}
		if (Clock::Instance().TimeZoneTrigger() && Clock::Instance().GetTimeZone() == night)
		{
			enemy2Summon.Resetting(5.0f);
		}
		else if (Clock::Instance().TimeZoneTrigger() && Clock::Instance().GetTimeZone() == morning)
		{
			enemy2Summon.Resetting(3.5f);
		}
		enemy2Summon.Update();
	}
	enemy1Summon.Update();
	//敵の生成
	if (enemy1Summon.IsTime())
	{
		//敵が出現する方向を決める
		float angle = (float)(GetRand(360));
		float radian = Util::AngleToRadian(angle);
		float spawnLength = Screen::WinWidth;
		Vector2 spawnPoint = Vector2((sin(radian) * spawnLength) + (Screen::WinWidth / 2), (cos(radian) * spawnLength) + (Screen::WinHight / 2));

		if (Clock::Instance().GetTimeZone() == morning)
		{
			new Enemy1(&spawnPoint, 1);
		}
		else if (Clock::Instance().GetTimeZone() == night)
		{
			new Enemy1(&spawnPoint, 2);
		}		
	}
	if (enemy2Summon.IsTime())
	{
		//敵が出現する方向を決める
		float angle = (float)(GetRand(360));
		float radian = Util::AngleToRadian(angle);
		float spawnLength = Screen::WinWidth;
		Vector2 spawnPoint = Vector2((sin(radian) * spawnLength) + (Screen::WinWidth / 2), (cos(radian) * spawnLength) + (Screen::WinHight / 2));

		if (Clock::Instance().GetTimeZone() == morning)
		{
			new Enemy2(&spawnPoint, 1);
		}
		else if (Clock::Instance().GetTimeZone() == night)
		{
			new Enemy2(&spawnPoint, 1);
		}
	}
	////敵の生成
	//if (enemy3Summon.IsTime())
	//{
	//	//敵が出現する方向を決める
	//	float angle = (float)(GetRand(360));
	//	float radian = Util::AngleToRadian(angle);
	//	float spawnLength = Screen::WinWidth;
	//	Vector2 spawnPoint = Vector2((sin(radian) * spawnLength) + (Screen::WinWidth / 2), (cos(radian) * spawnLength) + (Screen::WinHight / 2));

	//	if (Clock::Instance().GetTimeZone() == morning)
	//	{
	//		new Enemy3(&spawnPoint, 3);
	//	}
	//	else if (Clock::Instance().GetTimeZone() == night)
	//	{
	//		new Enemy3(&spawnPoint, 6);
	//	}
	//}
}

//描画処理
void GamePlay::Draw()
{
	DrawString(0, 0, "play", GetColor(255, 255, 255));
	GameObjectManager::Instance()->Draw();
	MousePointer::Instance()->Draw();
}

//次のシーン
Scene GamePlay::Next()
{
	if (Clock::Instance().GetElapsedTime() >= 2)
	{
		return gameClear;
	}
	return gameOver;
}

//現在のシーン
Scene GamePlay::CurrentScene()
{
	return gamePlay;
}
