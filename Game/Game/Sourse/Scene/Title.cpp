#include "Title.h"

#include "Vector2.h"
#include "KeyBoard.h"
#include"DxLib.h"
#include "Sound.h"
#include "Renderer.h"
#include "MousePointer.h"
#include "Controller.h"
#include "Font.h"



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
	if (Controller::Instance()->GetButtonTrigger(PAD_INPUT_4) || KeyBoard::GetKeyTrigger(KEY_INPUT_RETURN))
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
	DrawStringToHandle(220, 400, "TimeBullet", GetColor(255, 255, 255),Font::pixelM64);
	//DrawStringToHandle(100, 330, "Press Enter", GetColor(255, 255, 255));
	DrawStringToHandle(100, 100, "操作", GetColor(255, 255, 255),Font::pixelM16);
	DrawStringToHandle(100, 120, "B：弾の発射", GetColor(255, 255, 255),Font::pixelM16);
	DrawStringToHandle(100, 140, "RT：貫通弾の発射", GetColor(255, 255, 255),Font::pixelM16);
	DrawStringToHandle(100, 160, "LT：貫通弾の加速", GetColor(255, 255, 255),Font::pixelM16);
	DrawStringToHandle(100, 180, "X：遅範囲の発生", GetColor(255, 255, 255),Font::pixelM16);
	DrawStringToHandle(100, 200, "特殊弾は朝になると補充されます", GetColor(255, 255, 255),Font::pixelM16);
	//DrawString(100, 220, "デフォルト：キーボード、１キー：キーボード、２キー：コントローラー　切り替え", GetColor(255, 255, 255));
	DrawBox(90, 90, 400, 230, GetColor(255, 0, 0),0);
	MousePointer::Instance()->Draw();
	DrawCircle(353, 707, 10, GetColor(255, 0, 0));
	DrawString(350, 700, "B", GetColor(255, 255, 255));
	DrawStringToHandle(400, 700, "プレイ", GetColor(255, 255, 255),Font::pixelM16);
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
