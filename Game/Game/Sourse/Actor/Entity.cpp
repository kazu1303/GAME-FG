#include "Entity.h"



Entity::Entity(Vector2* position, CharaType type, bool entity, float scale, int hp, std::string name)
	:GameObject(position, type, entity, scale,hp,name )
{
}


Entity::~Entity()
{
}

//初期化処理
void Entity::Initialize()
{
}

//毎フレーム処理
void Entity::Update()
{
	GameObject::Update();
}

//描画処理
void Entity::Draw()
{
}

//ヒット処理
void Entity::Hit(GameObject * obj)
{
}
