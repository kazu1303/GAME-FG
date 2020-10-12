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
	void Update();
	Vector2 GetPosition();
	void Draw();
};

