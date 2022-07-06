#pragma once
#include "framework.h"
#include "Player.h"
#include "Vec2.h"
class Bullets
{
public:
	Bullets(float x, float y, float r)
		:
		vec(x, y),
		r(r)
	{}
	~Bullets() {}
	void draw(HDC hdc)
	{
		Ellipse(hdc, vec.GetX() - r, vec.GetY() - r, vec.GetX() + r, vec.GetY() + r);
	}
	void Shoot(Vec2 vec1, Vec2 vec2)
	{
		//단위 벡터
		vec.angle(vec1, vec2);
	}
private:
	Vec2 vec;
	float r = 10;//bullets의 좌표와 반지름
};

