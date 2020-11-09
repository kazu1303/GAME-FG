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
	//�E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

    //�E�B���h�E�T�C�Y���蓮�ł͕ύX�ł����A

    //���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���

    SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	//SetMainWindowsText(); �^�C�g���̕ύX

	//��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�i���j�^�[�̉𑜓x�Ɂj
	SetGraphMode(Screen::WinWidth, Screen::WinHight, 32);

	//��ʃT�C�Y��ݒ�i�𑜓x�̔䗦�j
	SetWindowSizeExtendRate(1, 0);

	//��ʂ̔w�i�F��ݒ�
	SetBackgroundColor(0, 0, 0);

    //Dx���C�u������������

    if (DxLib_Init() == -1)
    {
	    //�G���[���o����}�C�i�X�l��Ԃ��ďI��
	    return -1;
    }
	//�����_���[����
	Renderer* renderer;
	renderer = new Renderer();
	//�摜�̃��[�h
	renderer->Load();
	//�T�E���h�̐���
	Sound* sound;
	sound = new Sound();
	//���y�̃��[�h
	sound->Load();
	//�V�[���}�l�[�W���[����
	SceneManager*  sceneManager;
	sceneManager = new SceneManager();
	//�V�[���̒ǉ�
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
	//�f�B�X�v���C�̐���
	Display* display;
	display = new Display();
	//�}�X�N�̐���
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

    //�����������܂őҋ@

    WaitKey();

    //Dx���C�u�����I������

    DxLib_End();

    return 0;

}