#pragma once
#include <iostream>
#include <cmath>
class Vec2
{
private:
	float x, y;
public:
	Vec2() { x = 0; y = 0; }

	Vec2(Vec2& vec)
	{
		x = vec.x;
		y = vec.y;
	}
	Vec2(float x, float y)
		:
		x(x), y(y)
	{}
	~Vec2() {};
	const bool operator==(Vec2& vec)
	{
		if (x == vec.x && y == vec.y)
			return true;
		else
			return false;
	}
	const bool operator!=(Vec2& vec)
	{
		if (x != vec.x && y != vec.y)
			return true;
		else return false;
	}
	float operator+(Vec2& vec)
	{
		return (x + vec.x, y + vec.y);
	}
	float operator-(Vec2& vec)
	{
		return (x - vec.x, y - vec.y);
	}
	float operator*(float d)
	{
		return (x * d, y * d);
	}
	float operator/(float d)
	{
		return (x / d, y / d);
	}
	static float Dot(Vec2& v1, Vec2& v2)
	{
		return (v1.x * v2.x) + (v1.y * v2.y);
	}
	static Vec2 Cross(Vec2& v1, Vec2& v2)
	{
		Vec2 temp;
		return temp;
	}
	float GetX() const
	{
		return x;
	}
	float GetY() const
	{
		return y;
	}
	float Length()
	{
		return sqrt(x * x + y * y);
	}
	Vec2 Normalize()
	{
		Vec2 norm;
		norm.x = x / sqrt(x * x + y * y);
		norm.y = y / sqrt(x * x + y * y);
		return norm;
	}
	//단위벡터 만들기
	float angle(Vec2& v1, Vec2& v2)
	{
		float angle;
		angle = acos(Vec2::Dot(v1, v2) / (v1.Length() * v2.Length()));
		angle = angle * 180 / 3.142592;
		return angle;
	}
};
