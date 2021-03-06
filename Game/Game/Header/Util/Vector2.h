#pragma once
#include <math.h>
const float PI = (float)acos(-1);//円周率
class Vector2
{
public:
	float x, y;
	Vector2();
	Vector2(float X ,float Y);
	~Vector2();
	//円を描くように位置を変える
	void AngleToVector(float angle);
	//単位ベクトル化
	void Normalize();
	//ゼロに
	void Zero();
	void ReSetting(float X, float Y);
	float Length();


	Vector2 operator +(Vector2& value);
    Vector2 operator -(Vector2& value);
	Vector2 operator *(Vector2& value);
	Vector2 operator /(Vector2& value);
	Vector2 operator +=(Vector2& value);
};

inline Vector2::Vector2()
{
}

inline Vector2::Vector2(float X, float Y)
{
	x = X;
	y = Y;
}

inline Vector2::~Vector2()
{}

inline Vector2 Vector2::operator+(Vector2& value)
{
	return Vector2(x += value.x,y += value.y);
}

inline Vector2 Vector2::operator-(Vector2& value)
{
	return Vector2(x -= value.x, y -= value.y);
}

inline Vector2 Vector2::operator*(Vector2& value)
{
	return Vector2(x *= value.x, y *= value.y);
}

inline Vector2 Vector2::operator/(Vector2& value)
{
	return Vector2(x /= value.x, y /= value.y);
}

inline Vector2 Vector2::operator+=(Vector2& value)
{
	return Vector2(x += value.x, y += value.y);
}

//円を描くように位置を変える
inline void Vector2::AngleToVector(float angle)
{
	float thisangle = angle;
	thisangle = thisangle * PI / 180.0f;
	x = (float)sin(thisangle);
	y = (float)cos(thisangle);
}

//単位ベクトル化
inline void Vector2::Normalize()
{
	float length = sqrtf((x * x) + (y * y));
	x /= length;
	y /= length;
	if (length == 0)
	{
		x = 0;
		y = 0;
	}
}

//ゼロに
inline void Vector2::Zero()
{
	x = 0;
	y = 0;
}

inline void Vector2::ReSetting(float X, float Y)
{
	x = X;
	y = Y;
}

inline float Vector2::Length()
{
	return sqrtf((x * x) + (y * y));
}

 