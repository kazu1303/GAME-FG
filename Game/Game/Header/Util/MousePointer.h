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
	//–ˆƒtƒŒ[ƒ€ˆ—
	void Update();
	//À•W‚Ìæ“¾
	Vector2 GetPosition();
	//•`‰æˆ—
	void Draw();
};

