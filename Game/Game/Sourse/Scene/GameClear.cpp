#include "GameClear.h"
//#include "Screen.h"
#include "DxLib.h"
//#include "Renderer.h"
#include "KeyBoard.h"
#include "Controller.h"
#include "GameObjectManager.h"
#include "ParticleManager.h"

GameClear::GameClear()
{
	isEnd = false;
	push = true;
}


GameClear::~GameClear()
{
}

//初期化処理
void GameClear::Initialize()
{
	push = true;
	isEnd = false;
}

//毎フレーム処理
void GameClear::Update()
{
	//次のシーンへの変更処理
	if (Controller::Instance()->GetButtonTrigger(PAD_INPUT_4) || KeyBoard::GetKeyTrigger(KEY_INPUT_RETURN))
	{
		isEnd = true;
	}
	GameObjectManager::Instance()->Update();
	ParticleManager::Instance()->Update();
}

//描画処理
void GameClear::Draw()
{
	//Renderer::Instance()->DrawTexture1("gameclear", new Vector2((float)(Screen::WinWidth / 2.0f), (float)(Screen::WinHight / 2.0f)), 0.0f, 6.0f);
	//Renderer::Instance()->DrawTexture1("enter", new Vector2((float)(Screen::WinWidth / 2.0f), (float)(Screen::WinHight - 200.0f)), 0);
	GameObjectManager::Instance()->Draw();
	ParticleManager::Instance()->Draw();
	DrawString(300, 400, "GameClear", GetColor(255, 255, 255));
	//DrawString(330, 330, "Press Enter", GetColor(255, 255, 255));
	DrawCircle(353, 707, 10, GetColor(255, 0, 0));
	DrawString(350, 700, "B", GetColor(255, 255, 255));
	DrawString(400, 700, "タイトル", GetColor(255, 255, 255));
}

//次のシーン
Scene GameClear::Next()
{
	return title;
}

//現在のシーン
Scene GameClear::CurrentScene()
{
	return gameClear;
}
