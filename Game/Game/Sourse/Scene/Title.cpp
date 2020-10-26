#include "Title.h"

#include "Vector2.h"
#include "KeyBoard.h"
#include"DxLib.h"
#include "Sound.h"
#include "Renderer.h"
#include "MousePointer.h"


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
	if (KeyBoard::GetKeyTrigger(KEY_INPUT_RETURN))
	{
		isEnd = true;
	}
}

//描画処理
void Title::Draw()
{
	GameObjectManager::Instance()->Draw();
	ParticleManager::Instance()->Draw();
	DrawString(0, 0, "title", GetColor(255, 255, 255));
	DrawString(330, 330, "Press Enter", GetColor(255, 255, 255));
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
