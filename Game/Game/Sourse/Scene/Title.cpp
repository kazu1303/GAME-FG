#include "Title.h"

#include "Vector2.h"
#include "KeyBoard.h"
#include"DxLib.h"
#include "Sound.h"
#include "Renderer.h"
#include "MousePointer.h"
#include "Controller.h"



Title::Title()
{
	isEnd = false;
	gameObjectManager = new GameObjectManager();
	particleManager = new ParticleManager();
}

Title::~Title()
{
}

//初期化処理
void Title::Initialize()
{
	isEnd = false;
	GameObjectManager::Instance()->Initialize();
	ParticleManager::Instance()->Initialize();
	Sound::Instance()->PlayBGM("fight.mp3");
}

//毎フレーム処理
void Title::Update()
{
	//次のシーンへの変更処理
	if (Controller::Instance()->GetKey(PAD_INPUT_12) || KeyBoard::GetKeyTrigger(KEY_INPUT_RETURN))
	{
		isEnd = true;
	}
	ParticleManager::Instance()->Update();
	if (KeyBoard::GetKeyTrigger(KEY_INPUT_A))
	{

	}
}

//描画処理
void Title::Draw()
{
	GameObjectManager::Instance()->Draw();
	ParticleManager::Instance()->Draw();
	DrawString(0, 0, "title", GetColor(255, 255, 255));
	DrawString(330, 330, "Press Enter", GetColor(255, 255, 255));
	DrawString(330, 100, "操作", GetColor(255, 255, 255));
	DrawString(300, 120, "マウス左：弾の発射", GetColor(255, 255, 255));
	DrawString(300, 140, "Z：特殊弾１の発射", GetColor(255, 255, 255));
	DrawString(300, 160, "スペース：特殊弾１の加速", GetColor(255, 255, 255));
	DrawString(300, 180, "X：特殊弾２の発射", GetColor(255, 255, 255));
	DrawString(300, 200, "特殊弾は10発ずつで朝になると補充されます", GetColor(255, 255, 255));
	DrawBox(290, 90, 700, 230, GetColor(255, 0, 0),0);
	MousePointer::Instance()->Draw();
}

//次のシーン
Scene Title::Next()
{
	return gamePlay;
}

//現在のシーン
Scene Title::CurrentScene()
{
	return title;
}
