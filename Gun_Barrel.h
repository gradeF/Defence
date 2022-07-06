#pragma once
#include "framework.h"
#include "Vec2.h"


class Gun_Barrel
{
public:
	Gun_Barrel(float x, float y,float r) :
		vec(x, y),
		r(r)
	{}
	void Draw(HDC hdc)
	{
		MoveToEx(hdc, vec.GetX(), vec.GetY(), NULL);
		LineTo(hdc, vec.GetX()-r, vec.GetY()+r);
	}
private:
	Vec2 vec;
	float r;
};

