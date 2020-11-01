#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"
class SlowArea :
	public GameObject
{
private:
	Timer deadTimer;
public:
	SlowArea(Vector2 *position);
	~SlowArea();
	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Hit(GameObject *obj)override;
};

