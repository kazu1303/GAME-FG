#pragma once
#include "GameObject.h"
#include "Vector2.h"
class PutBullet :
	public GameObject
{
private :
	float speed;
public:
	PutBullet(Vector2 *position);
	~PutBullet();
	void Initialize()override;
	void Update()override;
	void Draw()override;
};

