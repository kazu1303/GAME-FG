#pragma once
class Util
{
private:
public:
	//アングルをラジアンに
	static float AngleToRadian(float angel);
	//ラジアンをアングルに
	static float RadianToAngle(float radian);
	//アングルを0から360の間に
	static float Angle0To360(float angle);
	//３平方の定理
	static float LengthTry(float length1, float length2);
	//比率の取得
	static float Ratio(float value1, float value2);

	static int Index(float num);
};

