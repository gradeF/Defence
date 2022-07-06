#pragma once
#include "framework.h"
#include "Vec2.h"
#include "Gun_Barrel.h"

class Player
{
public:
	Player(float x, float y, float r)
		:
		vec(x, y),
		r(r),
		barrel(x,y)
	{}
	~Player() {}
	void DrawPlayer(HDC hdc) 
	{
		Ellipse(hdc, vec.GetX()- r, vec.GetY() - r, vec.GetX() + r, vec.GetY() + r);
	}
	float GetX() const
	{
		return vec.GetX();
	}
	float GetY() const
	{
		return vec.GetY();
	}
private:
	Vec2 vec;
	float r; //50
	RECT rect;
	Gun_Barrel barrel;
};

