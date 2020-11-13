#pragma once
#include "Particle.h"
class GreenPlus :
	public Particle
{
public:
	GreenPlus(Vector2 *position);
	~GreenPlus();
	//初期化処理
	virtual void Initialize();
	//毎フレーム処理
	virtual void Update();
	//描画処理
	virtual void Draw();
};

