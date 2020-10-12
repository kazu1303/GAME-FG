#pragma once
#include "GameObject.h"
#include "Vector2.h"
class PlayerBullet :
	public GameObject
{
public:
	PlayerBullet(Vector2 *position);
	~PlayerBullet();
	void Initialize()override;
	void Update()override;
	void Draw()override;
};

