#pragma once
#include <string>

#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"

class Player :
	public GameObject
{
private:
	Timer bulletTimer;//�e���˂̊Ԋu
	Timer healTimer;//�񕜂̊Ԋu
	int slowBulletNum;//slowBullet�̐�
	int putBulletNum;//putBullet�̐�
	int maxHp = 10;//�̗�
	bool operation;
public:
	Player(Vector2 *position);
	~Player();
	//������
	void Initialize()override;
	//���t���[������
	void Update()override;
	//�`�揈��
	void Draw()override;
	//�q�b�g���̏���
	void Hit(GameObject *obj)override;
	//�ʏ�e�̔��ˏ���
	void Firing();
	//PutBullet�̔��ˏ���
	void FiringPutBullet();
	//SlowBullet�̔��ˏ���
	void FiringSlowBullet();
	//�C��̕`��
	void BatteryDraw();
	//HP�Q�[�W�̕`��
	void DrawDamageGauge();
	//�A�C�R���̕`��
	void BulletIcon(Vector2 pos,std::string key, std::string name, int Color, int num);
	//�񕜏���
	void Heal();
};

