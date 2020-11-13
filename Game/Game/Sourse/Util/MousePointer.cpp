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

//���t���[������
void MousePointer::Update()
{
	int x, y;
	GetMousePoint(&x, &y);
	position.x = x;
	position.y = y;
}

//���W�̎擾
Vector2 MousePointer::GetPosition()
{

	return position;
}

//�`�揈��
void MousePointer::Draw()
{
	DrawCircle(position.x, position.y, 5, GetColor(255, 255, 255),0);
}
