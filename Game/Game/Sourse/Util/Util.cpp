#include "Util.h"

#include <math.h>



//角度をラジアンに
float Util::AngleToRadian(float angel)
{
	//円周率
	const float PI = (float)acos(-1);
	return angel * PI / 180.0f;
}

//ラジアンを角度に
float Util::RadianToAngle(float radian)
{
	//円周率
	const float PI = (float)acos(-1);
	return radian * 180.0f / PI;
}

//角度を0〜360内に変更
float Util::Angle0To360(float angle)
{
	//角度を０から３６０内に収める
	float currentAngle = (float)(fabs(angle - ((int)angle / 360) * 360));
	//角度が0以下の場合は360度から引き求める
	if (angle < 0)currentAngle = 360 - currentAngle;
	return currentAngle;
}



//三平方の定理より斜線以外の線の長さを取得
float Util::LengthTry(float length1, float length2)
{
	//三平方の定理より２線からもう一つの線(斜めではない方)の長さを求める
	float length = (float)(sqrt(length1 * length1 - length2 * length2));
	//length2がlength1より長くなるとlengthは0
	if (length2 >= length1)	length = 0;
	return length;
}

//比率の所得
float Util::Ratio(float value1, float value2)
{
	//1の方の比率を求める
	return value1 / (value1 + value2);
}

int Util::Index(float num)
{
	//int i = num / 2;
	if (num < 2)
	{
		return 0;
	}
	return 1 + Index(num / 2);
}
