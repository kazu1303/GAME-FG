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
	//�L�[�̍X�V
	void GetKeyState();
	//���t���[������
	void Update();
	//�����Ă��邩
	static bool IsHitKey(int KeyCoad);
	//�������u�Ԃ�
	static bool GetKeyTrigger(int KeyCoad);
	//�������u�Ԃ�
	static bool GetKeyRelease(int KeyCoad);
};

