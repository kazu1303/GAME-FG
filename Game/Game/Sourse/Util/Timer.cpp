#include "Timer.h"

Timer::Timer()
{
}

Timer::Timer(float maxTime,bool loop)
{
	this->maxtime = maxTime;
	this->loop = loop;
	Initialize();
}


Timer::~Timer()
{
}

//�Z�b�g�������Ԃ��o�߂�����
bool Timer::IsTime()
{
	return isTime;
}

//�^�C�}�[���O��
void Timer::Reset()
{
	time = 0.0f;
}

//�^�C�}�[��ݒ肵�����Ԃ�
void Timer::Max()
{
	time = maxtime;
}

//����������
void Timer::Initialize()
{
	isTime = false;
	maxtime *= 60;
	time = 0;
}

//�^�C�}�[�̎��Ԃ̍Đݒ�
void Timer::Resetting(float maxTime)
{
	this->maxtime = maxTime * 60;
}

//���t���[������
void Timer::Update()
{	
    isTime = false;
	//�^�C�}�[���ݒ肵�����Ԃ��o�߂����ꍇ�̏���
	if (time >= maxtime)
	{
		isTime = true;
		//���[�v����ꍇ�^�C�}�[���O��
		if (loop)
		{
			time = 0.0f;
		}
		else//���Ȃ��ꍇ�^�C����ݒ肵�����Ԃ�
		{
			time = maxtime;
		}
	}
	//�^�C�}�[���ݒ肵�����Ԃ��o�߂��ĂȂ��ꍇ�̏���
	else
	{
		time++;
	}
}
