#include "GreenPlus.h"
#include "Display.h"
#include "Dxlib.h"


GreenPlus::GreenPlus(Vector2 * position)
	:Particle(position)
{
	deadTimer = Timer(1.0f, false);
}


GreenPlus::~GreenPlus()
{
}

//初期化
void GreenPlus::Initialize()
{
}

//毎フレーム処理
void GreenPlus::Update()
{
	deadTimer.Update();
	position->y -= 1;
	if (deadTimer.IsTime())
	{
		isDead = true;
	}
}

//描画処理
void GreenPlus::Draw()
{
	Display::Instance()->SetScreen(Particle_Screen);
	DrawString(position->x, position->y, "+", GetColor(0, 255, 0));
}
