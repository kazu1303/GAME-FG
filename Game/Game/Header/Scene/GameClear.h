#pragma once
#include "GameScene.h"

class GameClear :
	public GameScene
{
private:
	bool push;
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

