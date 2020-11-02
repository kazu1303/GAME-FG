#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"
class PutBullet :
	public GameObject
{
private :
	float speed;
	Timer idelTimer;
	bool idel;
public:
	PutBullet(Vector2 *position);
	~PutBullet();
	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Hit(GameObject *obj)override;
	void Damege(int attack)override;
};

