#pragma once
#include "GameObject.h"
#include "Vector2.h"
class Enemy :
	public GameObject
{
public:
	Enemy(Vector2 *position);
	~Enemy();
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Hit(GameObject *obj)override;
};

