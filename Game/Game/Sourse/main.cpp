#include "DxLib.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "GameObjectManager.h"
#include "GameScene.h"
#include "Title.h"
#include "GamePlay.h"
#include "GameClear.h"
#include "GameOver.h"
#include "Screen.h"
#include "Renderer.h"
#include "Sound.h"
#include "Display.h"
#include "KeyBoard.h"
#include "MousePointer.h"
#include "Controller.h"

//const int WinWidth = 800;
//const int WinHight = 600;

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
)
{
	//ウィンドウモードに設定
	ChangeWindowMode(TRUE);

    //ウィンドウサイズを手動では変更できず、

    //かつウィンドウサイズに合わせて拡大できないようにする

    SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	//SetMainWindowsText(); タイトルの変更

	//画面サイズの最大サイズ、カラービット数を設定（モニターの解像度に）
	SetGraphMode(Screen::WinWidth, Screen::WinHight, 32);

	//画面サイズを設定（解像度の比率）
	SetWindowSizeExtendRate(1, 0);

	//画面の背景色を設定
	SetBackgroundColor(0, 0, 0);

    //Dxライブラリを初期化

    if (DxLib_Init() == -1)
    {
	    //エラーが出たらマイナス値を返して終了
	    return -1;
    }
	//レンダラー生成
	Renderer* renderer;
	renderer = new Renderer();
	//画像のロード
	renderer->Load();
	//サウンドの生成
	Sound* sound;
	sound = new Sound();
	//音楽のロード
	sound->Load();
	//シーンマネージャー生成
	SceneManager*  sceneManager;
	sceneManager = new SceneManager();
	//シーンの追加
	sceneManager->Add(title, new Title());
	sceneManager->Add(gamePlay, new GamePlay());
	sceneManager->Add(gameClear, new GameClear());
	sceneManager->Add(gameOver, new GameOver());
	sceneManager->Change(title);

	KeyBoard* keyBoard;
	keyBoard = new KeyBoard();

	MousePointer* mouse;
	mouse = new MousePointer();

	Controller* controller;
	controller = new Controller();
	//ディスプレイの生成
	Display* display;
	display = new Display();
	//マスクの生成
	display->MakeDrawScreen();
	while (1)
	{
		mouse->Update();
		keyBoard->GetKeyState();
		controller->Update();
		sceneManager->Update();

		keyBoard->Update();
		display->ClearScreen();
		sceneManager->Draw();
		display->DrawScreen();
		DrawString(100, 400, std::to_string(controller->DirectionCoordinate().x).c_str(), GetColor(255, 255, 255));
		DrawString(100, 420, std::to_string(controller->DirectionCoordinate().y).c_str(), GetColor(255, 255, 255));
		ScreenFlip();
		WaitTimer(20);
		if (ProcessMessage() == -1)break;
		if (CheckHitKey(KEY_INPUT_ESCAPE))break;
	    
	}

    //何か押されるまで待機

    WaitKey();

    //Dxライブラリ終了処理

    DxLib_End();

    return 0;

}