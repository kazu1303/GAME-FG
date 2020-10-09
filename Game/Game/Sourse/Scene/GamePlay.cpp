#include "GamePlay.h"
#include"DxLib.h"
#include "KeyBoard.h"

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
	push = true;
}

//毎フレーム処理
void GamePlay::Update()
{
	//次のシーンへの変更処理
	if (KeyBoard::GetKeyTrigger(KEY_INPUT_RETURN))
	{
		isEnd = true;
		//前のフレームでキーが押されていない場合シーン終了
		if (!push)
		{

		}
		push = true;
	}
	else//キーが押されてないときはpushをfalseに
	{
		push = false;
	}
}

//描画処理
void GamePlay::Draw()
{
	DrawString(0, 0, "play", GetColor(255, 255, 255));
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
