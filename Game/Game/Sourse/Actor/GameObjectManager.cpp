#include "GameObjectManager.h"
#include "Clock.h"

using namespace std;

vector<shared_ptr<GameObject>> GameObjectManager::gameObjects;
vector<shared_ptr<GameObject>> GameObjectManager::addgameObjects;

//vector<GameObject*>::iterator itr;

GameObjectManager* GameObjectManager::instance = nullptr;



GameObjectManager::GameObjectManager()
{
	instance = this;
	Initialize();
}

//�C���X�^���X
GameObjectManager * GameObjectManager::Instance()
{
	return instance;
}

//����������
void GameObjectManager::Initialize()
{
	//���ׂĂ�vector���N���A���T�C�Y�����킹��
	gameObjects.clear();
	addgameObjects.clear();
	gameObjects.shrink_to_fit();
	addgameObjects.shrink_to_fit();
}

//�u���b�N�ȊO�̃L������z��ɉ�����
void GameObjectManager::Add(GameObject* obj)
{
	shared_ptr<GameObject> addobj(obj);
	addgameObjects.push_back(addobj);
}

//���t���[������
void GameObjectManager::Update()
{
	//�V�����������ꂽ�I�u�W�F�N�g�̒ǉ�
	gameObjects.insert(gameObjects.end(), addgameObjects.begin(), addgameObjects.end());
	addgameObjects.clear();

	//�A�b�v�f�[�g
	for (auto obj1 : gameObjects)
	{
		for (auto obj2 : gameObjects)
		{
			obj1->SetPlayerPos(obj2->GetPos(), obj2->GetType());
		}
	}
	//�L�����N�^�[�̖��t���[������
	for (auto itr : gameObjects)
	{
		itr->Update();
	}

	HitToObject();
	//���S����
	//�L�����N�^�[�̎��S����
	for (auto itr = gameObjects.begin(); itr != gameObjects.end(); )
	{
		//���S���Ă���vector�������
		if ((*itr)->IsDead())
		{
		    itr  = gameObjects.erase(itr);
		}
		//���S���ĂȂ������玟�̃I�u�W�F�N�g������
		else
		{
			itr++;
		}
	}

	//�T�C�Y�����킹��
	gameObjects.shrink_to_fit();
}

//�`�揈��
void GameObjectManager::Draw()
{
	for (auto itr : gameObjects)
	{
		itr->Draw();
	}
}

//�q�b�g����
void GameObjectManager::HitToObject()
{
	//�q�b�g����
	for (auto obj1 : gameObjects)
	{
		//�����蔻�肪�Ȃ��ꍇ�������Ȃ�
		if (!obj1->EntityObject() ||
			obj1->IsDead())
		{
			continue;
		}
		for (auto obj2 : gameObjects)
		{
			//�������̂Ɠ����蔻�肪�Ȃ����̂͏������Ȃ�
			if (obj1->Equal(obj2.get()) ||
				!obj2->EntityObject() ||
				obj2->IsDead())
			{
				continue;
			}
			//�q�b�g���Ă�����q�b�g���̏���
			if (obj1->IsCollision(obj2.get()))
			{
				obj1->Hit(obj2.get());
			}
		}
	}
}

//�X�^�[�g���邩
bool GameObjectManager::Start()
{
	return false;
}

//���񂾂�
bool GameObjectManager::GameOver()
{
	return false;
}

//�N���A�������i�Q�[���v���C�ɕԂ��p�j
bool GameObjectManager::GameClear()
{
	return false;
}

//�N���A�������i���̃N���X���Ŏg���悤�j
bool GameObjectManager::ClearFlag()
{
	return false;
}

GameObjectManager::~GameObjectManager()
{
}
