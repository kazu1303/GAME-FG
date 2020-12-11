#include "GameScene.h"
#include "DxLib.h"

GameScene::GameScene()
{
	pixelMFont = LoadFontDataToHandle("Font/PixelMplus.dft", 0);
	pixelMFont64 = LoadFontDataToHandle("Font/PixelMplus_64.dft", 0);
}


GameScene::~GameScene()
{
}

//初期化処理
void GameScene::Initialize()
{
}

//毎フレーム処理
void GameScene::Update()
{
}

//描画処理
void GameScene::Draw()
{
}

//シーン終了
bool GameScene::IsEnd()
{
	return isEnd;
}

//次のシーン
Scene GameScene::Next()
{
	return Scene();
}

//現在のシーン
Scene GameScene::CurrentScene()
{
	return Scene();
}
