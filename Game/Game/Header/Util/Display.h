#pragma once
#include <map>


//�X�N���[��
enum ScreenID
{
	BossLeg_Screen,
	BossHead_Screen,
	Enemy_Screen,
	PlayerLeg_Screen,
	PlayerHead_Screen,
	Block_Screen,
	PlayerBullet_Screen,
	BossAttack_Screen,
	Firing_Screen,
	Particle_Screen,
	CloudofDust_Screen,
	BossDust_Screen,
	Item_Screen
};

class Display
{
private:
	std::map<ScreenID, int> screens;//�쐬�����X�N���[����ۑ�
	static Display* instance;//�C���X�^���X
	int screenNum = 13;//�쐬����X�N���[���̐�
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



