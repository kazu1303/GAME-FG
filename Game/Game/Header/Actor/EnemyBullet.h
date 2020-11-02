#pragma once
#include "GameObject.h"
#include "Vector2.h"
class EnemyBullet :
	public GameObject
{
public:
	EnemyBullet(Vector2 *position);
	~EnemyBullet();
	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Hit(GameObject *obj)override;
};

