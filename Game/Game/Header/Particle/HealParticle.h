#pragma once
#include "Particle.h"
class HealParticle :
	public Particle
{
private:
	float range;//範囲
public:
	HealParticle(Vector2 *position,float range);
	~HealParticle();
	//初期化処理
	virtual void Initialize();
	//毎フレーム処理
	virtual void Update();
	//描画処理
	virtual void Draw();
};

