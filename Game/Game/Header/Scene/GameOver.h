#pragma once
#include "GameScene.h"

class GameOver :
	public GameScene
{
private:
	bool push;
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

