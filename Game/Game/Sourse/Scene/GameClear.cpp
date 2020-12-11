#include "GameClear.h"
//#include "Screen.h"
#include "DxLib.h"
//#include "Renderer.h"
#include "KeyBoard.h"
#include "Controller.h"
#include "GameObjectManager.h"
#include "ParticleManager.h"
#include "Font.h"
#include "Star.h"
#include "Screen.h"

GameClear::GameClear()
{
	isEnd = false;
	starTimer = Timer(0.1f, true);
}


GameClear::~GameClear()
{
}

//����������
void GameClear::Initialize()
{
	isEnd = false;
	GameObjectManager::Instance()->Initialize();
}

//���t���[������
void GameClear::Update()
{
	//���̃V�[���ւ̕ύX����
	if (Controller::Instance()->GetButtonTrigger(PAD_INPUT_12) || KeyBoard::GetKeyTrigger(KEY_INPUT_RETURN))
	{
		isEnd = true;
	}
	GameObjectManager::Instance()->Update();
	ParticleManager::Instance()->Update();
	starTimer.Update();
	if (starTimer.IsTime())
	{
		new Star(new Vector2(GetRand(Screen::WinWidth), GetRand(Screen::WinHight)));
	}
}

//�`�揈��
void GameClear::Draw()
{
	//Renderer::Instance()->DrawTexture1("gameclear", new Vector2((float)(Screen::WinWidth / 2.0f), (float)(Screen::WinHight / 2.0f)), 0.0f, 6.0f);
	//Renderer::Instance()->DrawTexture1("enter", new Vector2((float)(Screen::WinWidth / 2.0f), (float)(Screen::WinHight - 200.0f)), 0);
	GameObjectManager::Instance()->Draw();
	ParticleManager::Instance()->Draw();
	DrawStringToHandle(Screen::WinWidth / 2 - 16 * 9, Screen::WinHight / 2 - 32, "GameClear", GetColor(255, 255, 0), Font::pixelM64);
	//DrawString(330, 330, "Press Enter", GetColor(255, 255, 255));
	//DrawCircle(353, 707, 10, GetColor(255, 0, 0));
	DrawString(350, 700, "START", GetColor(255, 255, 255));
	DrawString(400, 700, "�^�C�g��", GetColor(255, 255, 255));
}

//���̃V�[��
Scene GameClear::Next()
{
	return title;
}

//���݂̃V�[��
Scene GameClear::CurrentScene()
{
	return gameClear;
}
