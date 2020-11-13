#pragma once
#include"Vector2.h"
class MousePointer
{
private:
	static MousePointer* instance;
	Vector2 position;
public:
	MousePointer();
	~MousePointer();
	static MousePointer* Instance();
	//���t���[������
	void Update();
	//���W�̎擾
	Vector2 GetPosition();
	//�`�揈��
	void Draw();
};

