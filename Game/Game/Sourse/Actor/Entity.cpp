#include "Entity.h"



Entity::Entity(Vector2* position, CharaType type, bool entity, float scale, int hp, std::string name)
	:GameObject(position, type, entity, scale,hp,name )
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
