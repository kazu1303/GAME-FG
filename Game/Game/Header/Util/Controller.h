#pragma once
#include "Vector2.h"
#include "DxLib.h"
class Controller
{
private:
	static Controller* instance;
	Vector2 direction;
	DINPUT_JOYSTATE prev, current;
	bool prevbutton[28], currentbutton[28];
public:
	Controller();
	~Controller();
	static Controller* Instance();
	//���t���[������
	void Update();
	//�X�e�B�b�N��|���Ă������
	Vector2 DirectionCoordinate();
	bool GetButtonTrigger(int key);
	bool GetButton(int key);

	void Draw();
};

