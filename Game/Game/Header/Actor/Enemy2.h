#pragma once
#include "Enemy.h"
#include "Vector2.h"
class Enemy2 :
	public Enemy
{
public:
	Enemy2(Vector2 *position);
	~Enemy2();
	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Hit(GameObject *obj)override;
};

