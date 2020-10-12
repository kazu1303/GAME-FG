#include "MousePointer.h"
#include"DxLib.h"
MousePointer* MousePointer::instance;


MousePointer::MousePointer()
{
	instance = this;
}


MousePointer::~MousePointer()
{
}

MousePointer * MousePointer::Instance()
{
	return instance;
}

void MousePointer::Update()
{
	int x, y;
	GetMousePoint(&x, &y);
	position.x = x;
	position.y = y;
}

Vector2 MousePointer::GetPosition()
{

	return position;
}

void MousePointer::Draw()
{
	DrawCircle(position.x, position.y, 5, GetColor(255, 255, 255),0);
}
