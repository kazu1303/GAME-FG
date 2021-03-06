#include "HealParticle.h"
#include "DxLib.h"
#include "DisPlay.h"
#include "GreenPlus.h"

HealParticle::HealParticle(Vector2 *position,float range)
	:Particle(position)
{
	deadTimer = Timer(1.0f, false);
	this->range = range;
}


HealParticle::~HealParticle()
{
}

//初期化
void HealParticle::Initialize()
{
}

//毎フレーム処理
void HealParticle::Update()
{
	deadTimer.Update();
	if (GetRand(6) == 0)
	{
		new GreenPlus(new Vector2(position->x + (GetRand(range) - range / 2),position->y + (GetRand(range) - range / 2)));
	}
	if (deadTimer.IsTime())
	{
		isDead = true;
	}
}

//描画処理
void HealParticle::Draw()
{
}
