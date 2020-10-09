#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager()
{
	instance = this;
	Initialize();
}


SceneManager::~SceneManager()
{
}

//�C���X�^���X
SceneManager* SceneManager::Instance()
{
	return instance;
}

//����������
void SceneManager::Initialize()
{
	if (scenes.empty())
	{
		scenes = std::map<Scene, GameScene*>();
	}
	else
	{
		scenes.clear();
	}
}

//�V�[���؂�ւ�
void SceneManager::Change(Scene name)
{
	currentScene = scenes[name];
	currentScene->Initialize();
}

//���t���[������
void SceneManager::Update()
{
	currentScene->Update();
	if (currentScene->IsEnd())
	{
		Change(currentScene->Next());
	}
}

//�`�揈��
void SceneManager::Draw()
{
	currentScene->Draw();
}

//�V�[����������
void SceneManager::Add(Scene name,GameScene* scene)
{
	scenes.insert(std::make_pair(name, scene));
}

//���݂̃V�[��
Scene SceneManager::CurrentScene()
{
	return currentScene->CurrentScene();
}

