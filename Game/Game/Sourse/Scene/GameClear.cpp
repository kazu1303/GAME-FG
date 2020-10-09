#include "GameClear.h"
//#include "Screen.h"
#include "DxLib.h"
//#include "Renderer.h"

GameClear::GameClear()
{
	isEnd = false;
	push = true;
}


GameClear::~GameClear()
{
}

//����������
void GameClear::Initialize()
{
	push = true;
	isEnd = false;
}

//���t���[������
void GameClear::Update()
{
	//���̃V�[���ւ̕ύX����
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		//�O�̃t���[���ŃL�[��������Ă��Ȃ��ꍇ�V�[���I��
		if (!push)
		{
			isEnd = true;
		}
		push = true;
	}
	else//�L�[��������ĂȂ��Ƃ���push��false��
	{
		push = false;
	}
}

//�`�揈��
void GameClear::Draw()
{
	//Renderer::Instance()->DrawTexture1("gameclear", new Vector2((float)(Screen::WinWidth / 2.0f), (float)(Screen::WinHight / 2.0f)), 0.0f, 6.0f);
	//Renderer::Instance()->DrawTexture1("enter", new Vector2((float)(Screen::WinWidth / 2.0f), (float)(Screen::WinHight - 200.0f)), 0);
	DrawString(0, 0, "clear", GetColor(255, 255, 255));
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
