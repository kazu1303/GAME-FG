#pragma once
#include <map>
#include "GameScene.h"

class SceneManager
{
private:
	std::map<Scene, GameScene*> scenes;//�V�[����ۑ�
	static SceneManager* instance;//�C���X�^���X
	GameScene* currentScene;//����������V�[��
public:
	SceneManager();
	~SceneManager();
	//�C���X�^���X
	static SceneManager* Instance();
	//����������
	void Initialize();
	//�V�[���؂�ւ�
	void Change(Scene name);
	//���t���[������
	void Update();
	//�`�揈��
	void Draw();
	//�V�[���̒ǉ�
	void Add(Scene name,GameScene* scene);
	//���݂̃V�[��
	Scene CurrentScene();
};

