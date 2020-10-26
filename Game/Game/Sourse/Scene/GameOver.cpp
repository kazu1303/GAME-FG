#include "GameOver.h"
//#include "Screen.h"
#include "DxLib.h"
//#include "Renderer.h"
#include "KeyBoard.h"

GameOver::GameOver()
{
	isEnd = false;
	push = true;
}


GameOver::~GameOver()
{
}

//����������
void GameOver::Initialize()
{
	push = true;
	isEnd = false;
}

//���t���[������
void GameOver::Update()
{
	//���̃V�[���ւ̕ύX����
	if (KeyBoard::GetKeyTrigger(KEY_INPUT_RETURN))
	{
		isEnd = true;
	}
}

//�`�揈��
void GameOver::Draw()
{
	//Renderer::Instance()->DrawTexture1("gameover", new Vector2((float)(Screen::WinWidth / 2.0f), (float)(Screen::WinHight / 2.0f)), 0.0f, 6.0f);
	//Renderer::Instance()->DrawTexture1("enter", new Vector2((float)(Screen::WinWidth / 2.0f), (float)(Screen::WinHight - 200.0f)), 0);
	DrawString(0, 0, "over", GetColor(255, 255, 255));
	DrawString(330, 330, "Press Enter", GetColor(255, 255, 255));
}

//���̃V�[��
Scene GameOver::Next()
{
	return title;
}

//���݂̃V�[��
Scene GameOver::CurrentScene()
{
	return gameOver;
}
