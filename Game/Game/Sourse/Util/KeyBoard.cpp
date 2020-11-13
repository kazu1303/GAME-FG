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

//�L�[���͂̍X�V
void KeyBoard::GetKeyState()
{
	GetHitKeyStateAll(currentKey);
}

//prev�X�V
void KeyBoard::Update()
{

	for (int i = 0; i < 256; i++)
	{
		prevKey[i] = currentKey[i];
	}
}

//�����Ă��邩
bool KeyBoard::IsHitKey(int KeyCoad)
{
	if (currentKey[KeyCoad] == 1)
	{
		return true;
	}
	return false;
}

//�������u�Ԃ�
bool KeyBoard::GetKeyTrigger(int KeyCoad)
{
	if (prevKey[KeyCoad] == 0 &&
		currentKey[KeyCoad] == 1)
	{
		return true;
	}
	return false;
}

//�������u�Ԃ�
bool KeyBoard::GetKeyRelease(int KeyCoad)
{
	if (prevKey[KeyCoad] == 1 &&
		currentKey[KeyCoad] == 0)
	{
		return true;
	}
	return false;
}
