#pragma once
class Util
{
private:
public:
	//�A���O�������W�A����
	static float AngleToRadian(float angel);
	//���W�A�����A���O����
	static float RadianToAngle(float radian);
	//�A���O����0����360�̊Ԃ�
	static float Angle0To360(float angle);
	//�R�����̒藝
	static float LengthTry(float length1, float length2);
	//�䗦�̎擾
	static float Ratio(float value1, float value2);

	static int Index(float num);
};

