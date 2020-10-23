#pragma once
#include "GameObject.h"
#include "Vector2.h"
class Enemy :
	public GameObject
{
public:
	Enemy(Vector2 *position);
	~Enemy();
	virtual void Initialize()override = 0;
	virtual void Update()override = 0;
	virtual void Draw()override = 0;
	virtual void Hit(GameObject *obj)override = 0;

};

