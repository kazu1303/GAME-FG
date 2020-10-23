#pragma once
#include <string>

#include "Vector2.h"


enum Direction
{
	Top,
	Bottom,
	Right,
	Left
};

enum CharaType
{
	player,
	player_bullet,
	enemy,
	clock,
};

//�I�u�W�F�N�g�̊��N���X
class GameObject
{
protected:
	Vector2* position = new Vector2(0,0);//���W
	Vector2* velocity = new Vector2(0,0);//�ړ���
	Vector2* otherPos = new Vector2(0,0);//��Ƀv���C���[�̍��W
	float size;
	float angle;//���ۂ̊p�x�A�`��̍ۂ̊p�x
	int hp;//�̗�
    bool isDead;//���S�^�U
	bool entity;//�����蔻��^�U
	CharaType type;//�L�����N�^�[�̃^�C�v
public:
	GameObject(Vector2* position, CharaType type, bool entity, float scale = 1.0f,int hp = 1,std::string name = " " );
	virtual ~GameObject();
	//����������
	virtual void Initialize();
	//���t���[������
	virtual void Update();
	//�`�揈��
	virtual void Draw();
	//���S�̐^�U
	bool IsDead();
	//�q�b�g����
	virtual void Hit(GameObject* obj);
	//���I�u�W�F�N�g���̐^�U
	bool Equal( GameObject* other);
	//��{�I�ȓ����蔻��i�l�p�`�j
	bool IsCollision(GameObject* other);
	//�q�b�g����������Ԃ�
	Direction CheckDirection( GameObject* other);
	//�L�����^�C�v��Ԃ�
	virtual CharaType GetType();
	//�����蔻��̐^�U
	virtual bool EntityObject();
	//�I�u�W�F�N�g�̍��W��Ԃ�
	Vector2* GetPos();
	//��Ƀv���C���[�̍��W��ݒ肷��p
	virtual void SetPlayerPos(Vector2* position,CharaType type);
};




