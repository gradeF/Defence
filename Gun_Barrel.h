#pragma once
#include "framework.h"
#include "Vec2.h"


class Gun_Barrel
{
public:
	Gun_Barrel(float x, float y) :
		vec(x, y)
	{}
	void Draw(HDC hdc)
	{
		MoveToEx(hdc, vec.GetX(), vec.GetY(), NULL);
		LineTo(hdc, x, y);
	}
	void MoveToRight()
	{
	}
	void MoveToLeft()
	{

	}
private:
	Vec2 vec;
	float r;//Ω√¿€¡°
};

