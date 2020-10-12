#include "GamePlay.h"
#include"DxLib.h"
#include "KeyBoard.h"
#include "Player.h"
#include "Screen.h"
#include "GameObjectManager.h"
#include "MousePointer.h"
#include "Util.h"
#include "Enemy1.h"
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
	enemy1Summon = Timer(1.5f, true);
	new Player(new Vector2(Screen::WinWidth / 2, Screen::WinHight / 2));
	new Clock(new Vector2(50, 50));
}

//毎フレーム処理
void GamePlay::Update()
{
	//次のシーンへの変更処理
	if (KeyBoard::GetKeyTrigger(KEY_INPUT_RETURN))
	{
		isEnd = true;
	}

	GameObjectManager::Instance()->Update();

	enemy1Summon.Update();
	//敵の生成
	if (enemy1Summon.IsTime())
	{
		//敵が出現する方向を決める
		float angle = (float)(GetRand(360));
		float radian = Util::AngleToRadian(angle);
		float spawnLength = Screen::WinHight;
		Vector2 spawnPoint = Vector2((sin(radian) * spawnLength) + (Screen::WinWidth / 2), (cos(radian) * spawnLength) + (Screen::WinHight / 2));
		new Enemy1(&spawnPoint);
	}
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
	return gameOver;
}

//現在のシーン
Scene GamePlay::CurrentScene()
{
	return gamePlay;
}
