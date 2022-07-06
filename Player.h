#pragma once
#define _USE_MATH_DEFINES
#include "framework.h"
#include "Vec2.h"
#include "Gun_Barrel.h"
#include "Bullets.h"
#include <cmath>

class Player
{
public:
	Player(float x, float y, float r)
		:
		vec(x, y),
		r(r),
		barrel(x, y,r),
		bullets(x, y)
	{}
	~Player() {}
	void Draw(HDC hdc) 
	{
		barrel.Draw(hdc);
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
	void moveBarrel(HDC hdc)
	{
		float x = vec.GetX() * r * cos( M_PI* 0.12f);
		float y = vec.GetY() * r * sin(M_PI * 0.12f);
		barrel.Draw(hdc);
	}
private:
	Vec2 vec;
	float r; //50
	RECT rect;
	Gun_Barrel barrel;
	Bullets bullets;
};

