#pragma once
class KeyBoard
{
private:
	static KeyBoard* instance;

public:
	static char prevKey[256];
	static char currentKey[256];

	static KeyBoard* Instance();
	KeyBoard();
	~KeyBoard();
	void GetKeyState();
	void Update();
	static bool IsHitKey(int KeyCoad);
	static bool GetKeyTrigger(int KeyCoad);
	static bool GetKeyDown(int KeyCoad);
};

