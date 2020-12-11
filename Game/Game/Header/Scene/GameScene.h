#pragma once

enum Scene
{
	title,
	gamePlay,
	gameClear,
	gameOver,
	load
};

//�V�[���̐e�N���X
class GameScene
{
protected:
	bool isEnd;
	int pixelMFont;
	int pixelMFont64;
public:
	GameScene();
	~GameScene();
	//����������
	virtual void Initialize();
	//���t���[������
	virtual void Update();
	//�`�揈��
	virtual void Draw();
	//�V�[���I��
	virtual bool IsEnd();
	//���̃V�[��
	virtual Scene Next();
	//���݂̃V�[��
	virtual Scene CurrentScene();
};

