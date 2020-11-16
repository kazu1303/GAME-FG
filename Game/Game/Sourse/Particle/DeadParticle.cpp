#include "DeadParticle.h"
#include "Display.h"
#include "Timer.h"
#include "DxLib.h"

DeadParticle::DeadParticle(Vector2* position)
	:Particle(position)
{
	deadTimer = Timer(0.3f, false);
	velocity->x = GetRand(50) - 25;
	velocity->y = GetRand(50) - 25;
	velocity->Normalize();
	speed = (float)GetRand(15) / 10;
}

DeadParticle::~DeadParticle()
{

}

void DeadParticle::Initialize()
{

}

void DeadParticle::Update()
{
	position->x += velocity->x * speed;
	position->y += velocity->y * speed;
	deadTimer.Update();
	if (deadTimer.IsTime())
	{
		isDead = true;
	}
}

void DeadParticle::Draw()
{
	Display::Instance()->SetScreen(Particle_Screen);
	DrawCircle(position->x, position->y,3.0f ,GetColor(255, 255, 255));
}