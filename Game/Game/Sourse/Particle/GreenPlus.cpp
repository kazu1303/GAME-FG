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

void GreenPlus::Initialize()
{
}

void GreenPlus::Update()
{
	deadTimer.Update();
	position->y -= 1;
	if (deadTimer.IsTime())
	{
		isDead = true;
	}
}

void GreenPlus::Draw()
{
	Display::Instance()->SetScreen(Particle_Screen);
	DrawString(position->x, position->y, "+", GetColor(0, 255, 0));
}
