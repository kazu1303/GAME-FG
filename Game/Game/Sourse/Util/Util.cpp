#include "Util.h"
#include <math.h>



//�p�x�����W�A����
float Util::AngleToRadian(float angel)
{
	//�~����
	const float PI = (float)acos(-1);
	return angel * PI / 180.0f;
}

//���W�A�����p�x��
float Util::RadianToAngle(float radian)
{
	//�~����
	const float PI = (float)acos(-1);
	return radian * 180.0f / PI;
}

//�p�x��0�`360���ɕύX
float Util::Angle0To360(float angle)
{
	//�p�x���O����R�U�O���Ɏ��߂�
	float currentAngle = (float)(fabs(angle - ((int)angle / 360) * 360));
	//�p�x��0�ȉ��̏ꍇ��360�x����������߂�
	if (angle < 0)currentAngle = 360 - currentAngle;
	return currentAngle;
}



//�O�����̒藝���ΐ��ȊO�̐��̒������擾
float Util::LengthTry(float length1, float length2)
{
	//�O�����̒藝���Q�����������̐�(�΂߂ł͂Ȃ���)�̒��������߂�
	float length = (float)(sqrt(length1 * length1 - length2 * length2));
	//length2��length1��蒷���Ȃ��length��0
	if (length2 >= length1)	length = 0;
	return length;
}

//�䗦�̏���
float Util::Ratio(float value1, float value2)
{
	//1�̕��̔䗦�����߂�
	return value1 / (value1 + value2);
}
