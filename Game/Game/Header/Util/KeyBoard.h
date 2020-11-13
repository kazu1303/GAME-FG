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
	//キーの更新
	void GetKeyState();
	//毎フレーム処理
	void Update();
	//押しているか
	static bool IsHitKey(int KeyCoad);
	//押した瞬間か
	static bool GetKeyTrigger(int KeyCoad);
	//離した瞬間か
	static bool GetKeyRelease(int KeyCoad);
};

