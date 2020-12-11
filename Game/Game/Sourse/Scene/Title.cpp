#include "Title.h"

#include "Vector2.h"
#include "KeyBoard.h"
#include"DxLib.h"
#include "Sound.h"
#include "Renderer.h"
#include "MousePointer.h"
#include "Controller.h"
#include "Font.h"



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
	if (Controller::Instance()->GetButtonTrigger(PAD_INPUT_4) || KeyBoard::GetKeyTrigger(KEY_INPUT_RETURN))
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
	DrawStringToHandle(220, 400, "TimeBullet", GetColor(255, 255, 255),Font::pixelM64);
	//DrawStringToHandle(100, 330, "Press Enter", GetColor(255, 255, 255));
	DrawStringToHandle(100, 100, "����", GetColor(255, 255, 255),Font::pixelM16);
	DrawStringToHandle(100, 120, "B�F�e�̔���", GetColor(255, 255, 255),Font::pixelM16);
	DrawStringToHandle(100, 140, "RT�F�ђʒe�̔���", GetColor(255, 255, 255),Font::pixelM16);
	DrawStringToHandle(100, 160, "LT�F�ђʒe�̉���", GetColor(255, 255, 255),Font::pixelM16);
	DrawStringToHandle(100, 180, "X�F�x�͈͂̔���", GetColor(255, 255, 255),Font::pixelM16);
	DrawStringToHandle(100, 200, "����e�͒��ɂȂ�ƕ�[����܂�", GetColor(255, 255, 255),Font::pixelM16);
	//DrawString(100, 220, "�f�t�H���g�F�L�[�{�[�h�A�P�L�[�F�L�[�{�[�h�A�Q�L�[�F�R���g���[���[�@�؂�ւ�", GetColor(255, 255, 255));
	DrawBox(90, 90, 400, 230, GetColor(255, 0, 0),0);
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
