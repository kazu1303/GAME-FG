#pragma once
#include "Particle.h"
class PlusBullet :
	public Particle
{
public:
	PlusBullet(Vector2 *position);
	~PlusBullet();
	//初期化処理
	virtual void Initialize();
	//毎フレーム処理
	virtual void Update();
	//描画処理
	virtual void Draw();
};

