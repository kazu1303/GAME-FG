#pragma once
#include <vector>
#include <memory>

#include "GameObject.h"




//�I�u�W�F�N�g���Ǘ�����N���X
class GameObjectManager
{
private:
	static GameObjectManager* instance;//�C���X�^���X
	//�u���b�N�ȊO�̃I�u�W�F�N�g������悤
	static std::vector<std::shared_ptr<GameObject>> gameObjects;//�L�������i�[
	static std::vector<std::shared_ptr<GameObject>> addgameObjects;//�V�������������L�������i�[

public:
	GameObjectManager();
	//�C���X�^���X
	static GameObjectManager* Instance();
	//����������
	void Initialize();
	//�u���b�N�ȊO�̃L������z��ɉ�����
	void Add(GameObject* obj);
	//���t���[������
	void Update();
	//�`�揈��
	void Draw();
	//�q�b�g����
	void HitToObject();
	//�X�^�[�g���邩
	bool Start();
	//���񂾂�
	bool GameOver();
	//�N���A������
	bool GameClear();
	//�N���A������
	bool ClearFlag();


	~GameObjectManager();
};