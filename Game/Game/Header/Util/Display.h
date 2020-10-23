#pragma once
#include <map>


//�X�N���[��
enum ScreenID
{
	Player_Screen,
	PlayerBattery_Screen,
	PlayerBullet_Screen,
	Enemy_Screen,
	SkyColor_Screen,
	UI_Screen,
	ScreenID_Length,
	
};

class Display
{
private:
	std::map<ScreenID, int> screens;//�쐬�����X�N���[����ۑ�
	static Display* instance;//�C���X�^���X
	int screenNum = ScreenID_Length;//�쐬����X�N���[���̐�
public:
	Display();
	~Display();
	//�C���X�^���X��Ԃ�
	static Display* Instance();
	//�}�X�N�̐���
	void MakeDrawScreen();
	//�쐬�����X�N���[����map�ɕۑ�
	void MakeDrawScreen(ScreenID id, int screen);
	//�}�X�N�̕`��̃N���A
	void ClearScreen();
	//�`�悷��}�X�N���Z�b�g
	void SetScreen(ScreenID id);
	//�S�}�X�N�̕`��
	void DrawScreen();
};



