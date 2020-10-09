#pragma once
#include "GameObject.h"
//�����蔻������I�u�W�F�N�g�̃N���X
class Entity :
	public GameObject
{
public:
	Entity(std::string name, Vector2* position, CharaType type, bool entity = true, float scale = 1, int hp = 1);
	~Entity();
	//����������
	virtual void Initialize()override;
	//���t���[������
	virtual void Update()override;
	//�`�揈��
	virtual void Draw()override;
	//�q�b�g����
	virtual void Hit(GameObject* obj)override;
};

