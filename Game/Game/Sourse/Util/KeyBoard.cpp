#include "KeyBoard.h"
#include"DxLib.h"

KeyBoard* KeyBoard::instance = nullptr;
char KeyBoard::prevKey[256];
char KeyBoard::currentKey[256];

KeyBoard * KeyBoard::Instance()
{
	return instance;
}

KeyBoard::KeyBoard()
{
	instance = this;
}


KeyBoard::~KeyBoard()
{
}

//キー入力の更新
void KeyBoard::GetKeyState()
{
	GetHitKeyStateAll(currentKey);
}

//prev更新
void KeyBoard::Update()
{

	for (int i = 0; i < 256; i++)
	{
		prevKey[i] = currentKey[i];
	}
}

//押しているか
bool KeyBoard::IsHitKey(int KeyCoad)
{
	if (currentKey[KeyCoad] == 1)
	{
		return true;
	}
	return false;
}

//押した瞬間か
bool KeyBoard::GetKeyTrigger(int KeyCoad)
{
	if (prevKey[KeyCoad] == 0 &&
		currentKey[KeyCoad] == 1)
	{
		return true;
	}
	return false;
}

//離した瞬間か
bool KeyBoard::GetKeyRelease(int KeyCoad)
{
	if (prevKey[KeyCoad] == 1 &&
		currentKey[KeyCoad] == 0)
	{
		return true;
	}
	return false;
}
