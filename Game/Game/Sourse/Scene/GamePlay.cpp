#include "GamePlay.h"
#include"DxLib.h"
#include "KeyBoard.h"
#include "Player.h"
#include "Screen.h"
#include "GameObjectManager.h"
#include "MousePointer.h"
#include "Util.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Clock.h"



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
	enemy1Summon = Timer(1.5f, true);
	enemy2Summon = Timer(0.8f, true);
	enemy3Summon = Timer(1.0f, true);
	new Player(new Vector2(Screen::WinWidth / 2, Screen::WinHight / 2));
	new Clock(new Vector2(50, 50));
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
	if (Clock::Instance().GetTimeZone() == morning)
	{
		enemy1Summon.Update();
		enemy3Summon.Update();
	}
	else if (Clock::Instance().GetTimeZone() == night)
	{
		enemy2Summon.Update();
	}

	//�G�̐���
	if (enemy1Summon.IsTime())
	{
		//�G���o��������������߂�
		float angle = (float)(GetRand(360));
		float radian = Util::AngleToRadian(angle);
		float spawnLength = Screen::WinHight;
		Vector2 spawnPoint = Vector2((sin(radian) * spawnLength) + (Screen::WinWidth / 2), (cos(radian) * spawnLength) + (Screen::WinHight / 2));
		new Enemy1(&spawnPoint);
	}
	if (enemy2Summon.IsTime())
	{
		//�G���o��������������߂�
		float angle = (float)(GetRand(360));
		float radian = Util::AngleToRadian(angle);
		float spawnLength = Screen::WinHight;
		Vector2 spawnPoint = Vector2((sin(radian) * spawnLength) + (Screen::WinWidth / 2), (cos(radian) * spawnLength) + (Screen::WinHight / 2));
		new Enemy2(&spawnPoint);
	}
	if (enemy3Summon.IsTime())
	{
		//�G���o��������������߂�
		float angle = (float)(GetRand(360));
		float radian = Util::AngleToRadian(angle);
		float spawnLength = Screen::WinHight;
		Vector2 spawnPoint = Vector2((sin(radian) * spawnLength) + (Screen::WinWidth / 2), (cos(radian) * spawnLength) + (Screen::WinHight / 2));
		new Enemy3(&spawnPoint);
	}
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
