#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"
class SlowBullet :
	public GameObject
{
private:
	Vector2 destination;
	Timer deadTimer;
public:
	SlowBullet(Vector2 *position);
	~SlowBullet();
	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Hit(GameObject *obj)override;
};

