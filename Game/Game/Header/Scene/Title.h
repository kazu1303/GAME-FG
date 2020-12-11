#pragma once
#include "GameScene.h"
#include "GameObjectManager.h"
#include "ParticleManager.h"
#include "Timer.h" 

class Title :
	public GameScene
{
private:
	GameObjectManager* gameObjectManager;
	ParticleManager* particleManager;
	Timer titleEnemyTimer;
	bool push;
public:
	Title();
	~Title();
	//����������
	void Initialize()override;
	//���t���[������
	void Update() override;
	//�`�揈��
	void Draw() override;
	//���̃V�[��
	virtual Scene Next() override;
	//���݂̃V�[��
	Scene CurrentScene()override;
};

