#pragma once
#include "GameScene.h"
#include "Timer.h"

class GameOver :
	public GameScene
{
private:
	Timer enemy1Summon;//�����Ԋu
	Timer enemy2Summon;//�����Ԋu
	Timer enemy3Summon;//�����Ԋu
public:
	GameOver();
	~GameOver();
	//����������
	void Initialize();
	//���t���[������
	void Update();
	//�`�揈��
	void Draw() override;
	//���̃V�[��
	virtual Scene Next() override;
	//���݂̃V�[��
	Scene CurrentScene()override;
};

