#include "GameOver.h"
//#include "Screen.h"
#include "DxLib.h"
//#include "Renderer.h"
#include "KeyBoard.h"
#include "Controller.h"

GameOver::GameOver()
{
	isEnd = false;
	push = true;
}


GameOver::~GameOver()
{
}

//初期化処理
void GameOver::Initialize()
{
	push = true;
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
}

//描画処理
void GameOver::Draw()
{
	//Renderer::Instance()->DrawTexture1("gameover", new Vector2((float)(Screen::WinWidth / 2.0f), (float)(Screen::WinHight / 2.0f)), 0.0f, 6.0f);
	//Renderer::Instance()->DrawTexture1("enter", new Vector2((float)(Screen::WinWidth / 2.0f), (float)(Screen::WinHight - 200.0f)), 0);
	DrawString(300, 400, "GameOver", GetColor(255, 255, 255));
	//DrawString(330, 330, "Press Enter", GetColor(255, 255, 255));
	DrawCircle(153, 707, 10, GetColor(0, 255, 0));
	DrawString(150, 700, "A", GetColor(255, 255, 255));
	DrawString(200, 700, "タイトル", GetColor(255, 255, 255));
	DrawCircle(403, 707, 10, GetColor(255, 0, 0));
	DrawString(400, 700, "B", GetColor(255, 255, 255));
	DrawString(450, 700, "リトライ", GetColor(255, 255, 255));
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
