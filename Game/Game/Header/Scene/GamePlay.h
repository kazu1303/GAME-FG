#pragma once
#include "GameScene.h"
#include "Timer.h"

class GamePlay:
	public GameScene
{
private:
	bool push;
	Timer enemy1Summon;//�g���{�̐����Ԋu
	Timer enemy2Summon;//�g���{�̐����Ԋu
	Timer enemy3Summon;//�g���{�̐����Ԋu
public:
	GamePlay();
	~GamePlay();
	//����������
	void Initialize()override;
	//���t���[������
	void Update()override;
	//�`�揈��
	void Draw() override;
	//���̃V�[��
	virtual Scene Next() override;
	//���݂̃V�[��
	Scene CurrentScene()override;
};

