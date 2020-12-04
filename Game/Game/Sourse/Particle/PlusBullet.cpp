#include "PlusBullet.h"
#include "DxLib.h"
#include "Display.h"

PlusBullet::PlusBullet(Vector2 *position)
	:Particle(position)
{
	deadTimer = Timer(0.5f, false);
}


PlusBullet::~PlusBullet()
{
}

void PlusBullet::Initialize()
{
}

void PlusBullet::Update()
{
	deadTimer.Update();
	position->y -= 2;
	if (deadTimer.IsTime())
	{
		isDead = true;
	}
}

void PlusBullet::Draw()
{
	Display::Instance()->SetScreen(Particle_Screen);
	DrawString(position->x, position->y, "+", GetColor(255, 255, 255));
	DrawCircle((int)(position->x + 13), (int)(position->y), 5, GetColor(135, 206, 250), 0);
	DrawCircle((int)(position->x + 13), (int)(position->y + 10), 5, GetColor(255, 255, 255), 0);
	//DrawString(position->x + 20, position->y, "Å~10", GetColor(255, 255, 255));
}
