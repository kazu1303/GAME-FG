#pragma once
class Timer
{
private:
	bool isTime;//�ݒ肵���b���̌o�߂̐^�U
	bool loop;//���[�v���邩
	float time,maxtime;//���ݎ��ԁA�ݒ莞��
public:
	Timer();
	Timer(float maxTime, bool loop);
	~Timer();
	//�Z�b�g�������Ԃ��o�߂�����
	bool IsTime();
	//�^�C�}�[���O��
	void Reset();
	//�^�C�}�[��ݒ肵�����Ԃ�
	void Max();
	//����������
	void Initialize();
	//�^�C�}�[�̎��Ԃ̍Đݒ�
	void Resetting(float maxTime);
	//�^�C�}�[�̌o�ߊ���
	float GetRate();
	//���t���[������
	void Update();
};

