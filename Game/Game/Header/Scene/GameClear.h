#pragma once
#include "GameScene.h"
#include "Timer.h"

class GameClear :
	public GameScene
{
private:
	Timer starTimer;
public:
	GameClear();
	~GameClear();
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

