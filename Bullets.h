#pragma once
#include "framework.h"
#include "Player.h"
#include "Vec2.h"
class Bullets
{
public:
	Bullets(float x, float y)
		:
		vec(x, y)
	{}
	~Bullets() {}
	void draw(HDC hdc)
	{
		Ellipse(hdc, vec.GetX() - r, vec.GetY() - r, vec.GetX() + r, vec.GetY() + r);
	}
private:
	Vec2 vec;
	float r = 10;//bullets의 좌표와 반지름
};

