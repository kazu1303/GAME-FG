#include "GameObject.h"
#include "GameObjectManager.h"
#include "DxLib.h"
#include "Renderer.h"

using namespace std;

GameObject::GameObject(Vector2* position, CharaType type, bool entity, float scale, int hp,string name)
{
	this->Name = name;
	this->position = new Vector2(position->x,position->y);
	this->type = type;
	this->entity = entity;
	isDead = false;
	this->hp = hp;
	if (Name != " ")
	{
		//�摜�T�C�Y����傫������
		GetGraphSize(Renderer::Instance()->Texture(Name), &imageSizeX, &imageSizeY);
		sizeX = imageSizeX * scale;
		sizeY = imageSizeY * scale;
		scaleX = scale;
		scaleY = scale;
	}

	GameObjectManager::Instance()->Add(this);
	
	Initialize();
}

GameObject::~GameObject()
{
	delete position;
	position = nullptr;
	delete velocity;
	velocity = nullptr;
	delete otherPos;
	otherPos = nullptr;
}

//����������
void GameObject::Initialize()
{
	velocity = new Vector2(0, 0);
}

//���t���[������
void GameObject::Update()
{
	position->x += velocity->x;
	position->y += velocity->y;
}

//�`�揈��
void GameObject::Draw()
{
}

//���S�̐^�U
bool GameObject::IsDead()
{
	return isDead;
}

//�q�b�g����
void GameObject::Hit(GameObject* obj)
{
}

//���I�u�W�F�N�g���̐^�U
bool GameObject::Equal(GameObject* other)
{
	return this == other;
}

//��{�I�ȓ����蔻��i�l�p�`�j
bool GameObject::IsCollision(GameObject * other)
{
	//���݂̋��������߂�
	Vector2 lengthXY(abs(this->position->x - other->position->x), abs(this->position->y - other->position->y));
	float length = lengthXY.Length();
	//	�I�u�W�F�N�g�̓����蔻��
	if ((length <= (this->size + other->size) / 2) &&
		(length <= (this->size + other->size) / 2))
	{
		return true;
	}
	return false;
}

//�u���b�N���m�̓����蔻��
bool GameObject::BBCollision(GameObject * other)
{
	float lengthX = abs(this->position->x - other->position->x);
	float lengthY = abs(this->position->y - other->position->y);
	//XY�����������Ƒ���̃T�C�Y/�Q�𑫂����l��菬�����ꍇ�̓q�b�g���Ă���̂�true��Ԃ�
	if ((lengthX < (this->sizeX + other->sizeX) / 2 - 1) &&
		(lengthY < (this->sizeY + other->sizeY) / 2 - 1))
	{
		return true;
	}
	return false;
}

//�q�b�g����������Ԃ�
Direction GameObject::CheckDirection( GameObject * other)
{	
	float lengthX = abs(this->position->x - other->position->x);
	float lengthY = abs(this->position->y - other->position->y);
	////��������̓�����������
	//if (other->GetType() == block &&
	//	this->GetType() != block)
	//{
	//	//X���Y�̕��������ꍇ
	//	if (lengthX < lengthY)
	//	{
	//		//�����莩����y���傫���ꍇ���ɐG��Ă���
	//		if (this->position->y >= other->position->y) return Bottom;
	//		//�����莩����y���������ꍇ��ɐG��Ă���
	//		else if (this->position->y <= other->position->y) return Top;
	//	}
	//	//Y���X�̕��������ꍇ
	//	else if (lengthY < lengthX)
	//	{
	//		//�����莩����x���������ꍇ���ɐG��Ă���
	//		if (this->position->x < other->position->x)	return Left;
	//		//����ȊO�͉E�ɐG��Ă���
	//		else return Right;
	//	}
	//}
	////�O������̓�����������
	//else
	//{
	//	lengthX -= (this->sizeX + other->sizeX);
	//	lengthY -= (this->sizeY + other->sizeY);
	//	//X���Y�̕��������ꍇ
	//	if (lengthX < lengthY)
	//	{
	//		//�����莩����y���������ꍇ���ɐG��Ă���
	//		if (this->position->y < other->position->y) return Bottom;
	//		//�����莩����y���傫���ꍇ��ɐG��Ă���
	//		else if (this->position->y > other->position->y) return Top;
	//	}
	//	//Y���X�̕��������ꍇ
	//	else
	//	{
	//		//�����莩����x���傫���ꍇ���ɐG��Ă���
	//		if (this->position->x > other->position->x)	return Left;
	//		//����ȊO�͉E�ɐG��Ă���
	//		else return Right;
	//	}
	//}
	return Right;
}

//�L�����^�C�v��Ԃ�
CharaType GameObject::GetType()
{
	return type;
}

//�����蔻��̐^�U
bool GameObject::EntityObject()
{
	return entity;
}

//�I�u�W�F�N�g�̍��W��Ԃ�
Vector2* GameObject::GetPos()
{
	return position;
}

//��Ƀv���C���[�̍��W��ݒ肷��p
void GameObject::SetPlayerPos(Vector2* position, CharaType type)
{
	//�v���C���[�̍��W�����ۑ�
	if (type == player)
	{
		otherPos = new Vector2(position->x, position->y);
	}

}




