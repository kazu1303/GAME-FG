#include "GamePlay.h"
#include"DxLib.h"
#include "KeyBoard.h"

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
	push = true;
}

//���t���[������
void GamePlay::Update()
{
	//���̃V�[���ւ̕ύX����
	if (KeyBoard::GetKeyTrigger(KEY_INPUT_RETURN))
	{
		isEnd = true;
		//�O�̃t���[���ŃL�[��������Ă��Ȃ��ꍇ�V�[���I��
		if (!push)
		{

		}
		push = true;
	}
	else//�L�[��������ĂȂ��Ƃ���push��false��
	{
		push = false;
	}
}

//�`�揈��
void GamePlay::Draw()
{
	DrawString(0, 0, "play", GetColor(255, 255, 255));
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
