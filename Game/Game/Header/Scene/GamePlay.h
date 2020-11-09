#pragma once
#include "GameScene.h"
#include "Timer.h"
#include "Player.h"

class GamePlay:
	public GameScene
{
private:
	bool push;
	Player* player;
	Timer enemy1Summon;//�����Ԋu
	Timer enemy2Summon;//�����Ԋu
	Timer enemy3Summon;//�����Ԋu
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

