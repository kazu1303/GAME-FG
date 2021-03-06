#pragma once
#include "Particle.h"
#include "Vector2.h"
#include "Timer.h"
class Star :
	public Particle
{
private:
	int angle;
	Timer deadTimer;
	int addAngle;
public:
	Star(Vector2 *position);
	~Star();
	//初期化処理
	virtual void Initialize()override;
	//毎フレーム処理
	virtual void Update()override;
	//描画処理
	virtual void Draw()override;
};

