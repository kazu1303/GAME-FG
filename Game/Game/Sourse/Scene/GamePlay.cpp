#include "GamePlay.h"
#include"DxLib.h"
#include "KeyBoard.h"
#include "Player.h"
#include "Screen.h"
#include "GameObjectManager.h"
#include "MousePointer.h"

GamePlay::GamePlay()
{

}

GamePlay::~GamePlay()
{
}

//����������
void GamePlay::Initialize()
{
	isEnd = false;
	new Player(new Vector2(Screen::WinWidth / 2, Screen::WinHight / 2));
}

//���t���[������
void GamePlay::Update()
{
	//���̃V�[���ւ̕ύX����
	if (KeyBoard::GetKeyTrigger(KEY_INPUT_RETURN))
	{
		isEnd = true;
	}
	GameObjectManager::Instance()->Update();
}

//�`�揈��
void GamePlay::Draw()
{
	DrawString(0, 0, "play", GetColor(255, 255, 255));
	GameObjectManager::Instance()->Draw();
	MousePointer::Instance()->Draw();
}

//���̃V�[��
Scene GamePlay::Next()
{
	return gameOver;
}

//���݂̃V�[��
Scene GamePlay::CurrentScene()
{
	return gamePlay;
}
