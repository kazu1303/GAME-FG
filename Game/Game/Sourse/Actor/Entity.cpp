#include "Entity.h"



Entity::Entity(std::string name, Vector2* position, CharaType type, bool entity, float scale, int hp)
	:GameObject(name,position, type, entity, scale,hp )
{
}


Entity::~Entity()
{
}

//����������
void Entity::Initialize()
{
}

//���t���[������
void Entity::Update()
{
	GameObject::Update();
}

//�`�揈��
void Entity::Draw()
{
}

//�q�b�g����
void Entity::Hit(GameObject * obj)
{
}