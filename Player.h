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
	Player()
		:
		center(0.0f, 0.0f),
		r(10),
		barrel(0.0f, 0.0f, r * 2.0f)
		//bullets(0.0f, 0.0f)
	{}

	Player(float x, float y, float r)
		:
		center(x, y),
		r(r),
		barrel(x, y,r)
		//bullets(x, y)
	{}
	~Player() {}
	void Draw(HDC hdc) 
	{
		barrel.Draw(hdc);
		Ellipse(hdc, center.x- r, center.y - r, center.x + r, center.y + r);
	}
	/*void moveBarrelRight()
	{
		barrel.vec2.x += barrel.vec2.x * cos( M_PI * 0.12f );
		barrel.vec2.y += barrel.vec2.y * sin( M_PI * 0.12f );
	}*/
private:
	Vec2<float> center;
	float r; //50
	RECT rect;
	Gun_Barrel barrel;
	//Bullets bullets;
};

