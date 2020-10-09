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

