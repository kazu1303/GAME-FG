#pragma once
#include "Enemy.h"
#include "Vector2.h"
class Enemy1 :
	public Enemy
{
public:
	Enemy1(Vector2 *position);
	~Enemy1();
	void Initialize()override;
	void Update()override;
	void Draw()override;
};

