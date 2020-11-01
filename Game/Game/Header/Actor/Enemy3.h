#pragma once
#include "Enemy.h"
#include "Vector2.h"
class Enemy3 :
	public Enemy
{
public:
	Enemy3(Vector2 *position,int hp);
	~Enemy3();
	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Hit(GameObject *obj)override;
};

