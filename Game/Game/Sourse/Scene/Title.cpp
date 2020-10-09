#include "Title.h"

#include "Vector2.h"
#include "KeyBoard.h"
#include"DxLib.h"
#include "Sound.h"
#include "Renderer.h"


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
	push = true;
	GameObjectManager::Instance()->Initialize();
	ParticleManager::Instance()->Initialize();
	Sound::Instance()->PlayBGM("fight.mp3");
}

//���t���[������
void Title::Update()
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
void Title::Draw()
{
	GameObjectManager::Instance()->Draw();
	ParticleManager::Instance()->Draw();
	DrawString(0, 0, "title", GetColor(255, 255, 255));
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
