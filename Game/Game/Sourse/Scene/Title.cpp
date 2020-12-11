#include "Title.h"

#include "Vector2.h"
#include "KeyBoard.h"
#include"DxLib.h"
#include "Sound.h"
#include "Renderer.h"
#include "MousePointer.h"
#include "Controller.h"
#include "Font.h"
#include "Player.h"
#include "Clock.h"
#include "TitleEnemy.h"
#include "Screen.h"
#include "Util.h"
#include "Display.h"


Title::Title()
{
	isEnd = false;
	gameObjectManager = new GameObjectManager();
	particleManager = new ParticleManager();
}

Title::~Title()
{
}

//����������
void Title::Initialize()
{
	isEnd = false;
	GameObjectManager::Instance()->Initialize();
	ParticleManager::Instance()->Initialize();
	Sound::Instance()->PlayBGM("fight.mp3");
	new Player(new Vector2((float)(Screen::WinWidth / 2), (float)(Screen::WinHight / 2)));
	new Clock(new Vector2(40.0f, 40.0f));
	titleEnemyTimer = Timer(1.0f, true);
}

//���t���[������
void Title::Update()
{
	//���̃V�[���ւ̕ύX����
	if (Controller::Instance()->GetButtonTrigger(PAD_INPUT_4) || KeyBoard::GetKeyTrigger(KEY_INPUT_RETURN))
	{
		isEnd = true;
	}
	ParticleManager::Instance()->Update();
	GameObjectManager::Instance()->Update();
	titleEnemyTimer.Update();
	if (titleEnemyTimer.IsTime())
	{
		//�G���o��������������߂�
		float angle = (float)(GetRand(360));
		float radian = Util::AngleToRadian(angle);
		float spawnLength = (float)Screen::WinWidth / 1.7f;
		Vector2 spawnPoint = Vector2((sin(radian) * spawnLength) + (Screen::WinWidth / 2), (cos(radian) * spawnLength) + (Screen::WinHight / 2));

		if (Clock::Instance().GetTimeZone() == morning)
		{
			new TitleEnemy(new Vector2(spawnPoint.x, spawnPoint.y));
		}
		else if (Clock::Instance().GetTimeZone() == night)
		{
			new TitleEnemy(new Vector2(spawnPoint.x, spawnPoint.y));
		}
	}
	if (KeyBoard::GetKeyTrigger(KEY_INPUT_A))
	{

	}
}

//�`�揈��
void Title::Draw()
{
	GameObjectManager::Instance()->Draw();
	ParticleManager::Instance()->Draw();
	Display::Instance()->SetScreen(UI_Screen);
	DrawStringToHandle(220, 100, "TimeBullet", GetColor(255, 255, 255),Font::pixelM64);
	//DrawStringToHandle(100, 330, "Press Enter", GetColor(255, 255, 255));
	//DrawStringToHandle(100, 100, "����", GetColor(255, 255, 255),Font::pixelM);
	//DrawStringToHandle(100, 120, "B�F�e�̔���", GetColor(255, 255, 255),Font::pixelM);
	//DrawStringToHandle(100, 140, "RT�F�ђʒe�̔���", GetColor(255, 255, 255),Font::pixelM);
	//DrawStringToHandle(100, 160, "LT�F�ђʒe�̉���", GetColor(255, 255, 255),Font::pixelM);
	//DrawStringToHandle(100, 180, "X�F�x�͈͂̔���", GetColor(255, 255, 255),Font::pixelM);
	DrawStringToHandle(Screen::WinWidth / 2 - 100, Screen::WinHight / 2 + 130, "����e�͒��ɂȂ�ƕ�[����܂�", GetColor(255, 255, 255),Font::pixelM);
	//DrawString(100, 220, "�f�t�H���g�F�L�[�{�[�h�A�P�L�[�F�L�[�{�[�h�A�Q�L�[�F�R���g���[���[�@�؂�ւ�", GetColor(255, 255, 255));
	//DrawBox(90, 90, 400, 230, GetColor(255, 0, 0),0);
	MousePointer::Instance()->Draw();
	DrawCircle(353, 707, 10, GetColor(255, 0, 0));
	DrawString(350, 700, "B", GetColor(255, 255, 255));
	DrawStringToHandle(400, 700, "�v���C", GetColor(255, 255, 255),Font::pixelM16);
}

//���̃V�[��
Scene Title::Next()
{
	return gamePlay;
}

//���݂̃V�[��
Scene Title::CurrentScene()
{
	return title;
}
