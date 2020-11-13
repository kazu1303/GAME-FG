#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Timer.h"

struct Color
{
	int r;
	int g;
	int b;
};

enum TimeZone
{
	morning,
	night
};

class Clock : public GameObject
{
private:
	Timer dayTimer;//1���̎���
	Vector2 clockHand;//�j�̐�[�̍��W
	static Clock* instance;
	static const int skyColorLength = 6;
	Color skyColors[skyColorLength] = {
		{ 155, 177, 177 },
		{ 210, 255, 255 },
		{ 255, 72, 0 },
		{ 85, 24, 0 },
		{ 42, 12, 0 },
		{ 0, 0, 0 },
	};
	TimeZone timeZone;//���݂̎��ԑ�
	TimeZone prevTimeZone;//��O�̎��ԑ�
	TimeZone currentTimeZone;//���݂̎��ԑ�
	bool timeZoneTrigger;//���ԑт��؂�ւ�����u��
	int day;//�o�ߓ���
public:
	static Clock& Instance();
	Clock(Vector2* position);
	~Clock();
	//����������
	void Initialize();
	//���t���[������
	void Update();
	//�`�揈��
	void Draw();
	//��̐F�̎擾
	Color GetSkyColor();
	//��̕`��
	void DrawSky();
	//�o�ߎ���
	float GetTime();
	//���ԑт̎擾
	TimeZone GetTimeZone();
	//���ԑт��؂�ւ������
	bool TimeZoneTrigger();
	//�o�ߓ�
	int GetElapsedTime();
};

