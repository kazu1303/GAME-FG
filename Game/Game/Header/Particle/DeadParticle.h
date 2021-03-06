#pragma once
#include "Particle.h"

class DeadParticle : public Particle
{
private:
	float speed;
public:
	DeadParticle(Vector2* position);
	~DeadParticle();
	//初期化処理
	virtual void Initialize();
	//毎フレーム処理
	virtual void Update();
	//描画処理
	virtual void Draw();
};
