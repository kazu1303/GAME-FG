#pragma once
#include "Enemy.h"
#include "Vector2.h"
class Enemy1 :
	public Enemy
{
private:

public:
	Enemy1(Vector2 *position,int hp);
	~Enemy1();
	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Hit(GameObject *obj)override;
};

