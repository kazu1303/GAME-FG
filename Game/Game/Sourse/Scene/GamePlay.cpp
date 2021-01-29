#include "GamePlay.h"
#include"DxLib.h"
#include "KeyBoard.h"
#include "Player.h"
#include "Screen.h"
#include "GameObjectManager.h"
#include "ParticleManager.h"
#include "MousePointer.h"
#include "Util.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Clock.h"
#include "Sound.h"
#include "Font.h"



GamePlay::GamePlay()
{

}

GamePlay::~GamePlay()
{
}

//初期化処理
void GamePlay::Initialize()
{
	GameObjectManager::Instance()->Initialize();
	ParticleManager::Instance()->Initialize();
	isEnd = false;
	enemy1Summon = Timer(1.5f, true);
	enemy2Summon = Timer(1.5f, true);
	enemy3Summon = Timer(2.0f, true);
	player = new Player(new Vector2((float)(Screen::WinWidth / 2), (float)(Screen::WinHight / 2)));
	new Clock(new Vector2(40.0f, 40.0f));
	Sound::Instance()->PlayBGM("gameplay.mp3");
}

//毎フレーム処理
void GamePlay::Update()
{
	//次のシーンへの変更処理
	if (player->IsDead())
	{
		isEnd = true;
	}
	if (Clock::Instance().GetElapsedTime() >= 3)
	{
		isEnd = true;
	}
	GameObjectManager::Instance()->Update();
	ParticleManager::Instance()->Update();
	if (Clock::Instance().GetElapsedTime() == 0)
	{
		if (Clock::Instance().TimeZoneTrigger() && Clock::Instance().GetTimeZone() == night)
		{
			enemy1Summon.Resetting(1.0f);
		}
		else if (Clock::Instance().TimeZoneTrigger() && Clock::Instance().GetTimeZone() == morning)
		{
			enemy1Summon.Resetting(1.5f);
		}
	}
	if (Clock::Instance().GetElapsedTime() == 1)
	{
		if (Clock::Instance().TimeZoneTrigger() && Clock::Instance().GetTimeZone() == night)
		{
			enemy1Summon.Resetting(1.0f);
			enemy3Summon.Resetting(3.5f);
		}
		else if (Clock::Instance().TimeZoneTrigger() && Clock::Instance().GetTimeZone() == morning)
		{
			enemy1Summon.Resetting(1.5f);
			enemy3Summon.Resetting(7.0f);
			enemy3Summon.Max();
		}
		enemy3Summon.Update();
	}
	if (Clock::Instance().GetElapsedTime() == 2)
	{
		if (Clock::Instance().TimeZoneTrigger() && Clock::Instance().GetTimeZone() == night)
		{
			enemy1Summon.Resetting(1.0f);
			enemy2Summon.Resetting(4.0f);
			enemy3Summon.Resetting(3.5f);
		}
		else if (Clock::Instance().TimeZoneTrigger() && Clock::Instance().GetTimeZone() == morning)
		{
			enemy1Summon.Resetting(1.5f);
			enemy2Summon.Resetting(8.0f);
			enemy3Summon.Resetting(7.0f);
			enemy2Summon.Max();
		}
		enemy2Summon.Update();
		enemy3Summon.Update();
	}
	enemy1Summon.Update();
	//敵の生成
	if (enemy1Summon.IsTime())
	{
		//敵が出現する方向を決める
		float angle = (float)(GetRand(360));
		float radian = Util::AngleToRadian(angle);
		float spawnLength = (float)Screen::WinWidth / 1.5f;
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
		float spawnLength = (float)Screen::WinWidth / 1.5f;
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
		float spawnLength = (float)Screen::WinWidth / 1.5f;
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
}

//描画処理
void GamePlay::Draw()
{
	//DrawString(0, 0, "play", GetColor(255, 255, 255));
	GameObjectManager::Instance()->Draw();
	MousePointer::Instance()->Draw();
	ParticleManager::Instance()->Draw();
	DrawStringToHandle(Screen::WinWidth - 150, Screen::WinHight - 64, std::to_string(Clock::Instance().GetElapsedTime() + 1).c_str(), GetColor(255, 255, 255), Font::pixelM64);
	DrawStringToHandle(Screen::WinWidth - 100, Screen::WinHight - 64, "Day", GetColor(255, 255, 255), Font::pixelM64);
}

//次のシーン
Scene GamePlay::Next()
{
	Sound::Instance()->StopBGM();
	if (Clock::Instance().GetElapsedTime() >= 3)
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
