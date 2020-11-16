#include "Title.h"

#include "Vector2.h"
#include "KeyBoard.h"
#include"DxLib.h"
#include "Sound.h"
#include "Renderer.h"
#include "MousePointer.h"
#include "Controller.h"



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
}

//���t���[������
void Title::Update()
{
	//���̃V�[���ւ̕ύX����
	if (Controller::Instance()->GetKey(PAD_INPUT_12) || KeyBoard::GetKeyTrigger(KEY_INPUT_RETURN))
	{
		isEnd = true;
	}
	ParticleManager::Instance()->Update();
	if (KeyBoard::GetKeyTrigger(KEY_INPUT_A))
	{

	}
}

//�`�揈��
void Title::Draw()
{
	GameObjectManager::Instance()->Draw();
	ParticleManager::Instance()->Draw();
	DrawString(0, 0, "title", GetColor(255, 255, 255));
	DrawString(330, 330, "Press Enter", GetColor(255, 255, 255));
	DrawString(330, 100, "����", GetColor(255, 255, 255));
	DrawString(300, 120, "�}�E�X���F�e�̔���", GetColor(255, 255, 255));
	DrawString(300, 140, "Z�F����e�P�̔���", GetColor(255, 255, 255));
	DrawString(300, 160, "�X�y�[�X�F����e�P�̉���", GetColor(255, 255, 255));
	DrawString(300, 180, "X�F����e�Q�̔���", GetColor(255, 255, 255));
	DrawString(300, 200, "����e��10�����Œ��ɂȂ�ƕ�[����܂�", GetColor(255, 255, 255));
	DrawBox(290, 90, 700, 230, GetColor(255, 0, 0),0);
	MousePointer::Instance()->Draw();
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
