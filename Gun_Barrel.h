#pragma once
#define _USE_MATH_DEFINES
#include "framework.h"
#include "Vec2.h"

#include <math.h>
class Gun_Barrel
{
public:
	Gun_Barrel(float x, float y,float r) :
		vec(x, y),
		r(r),
		vec2(x-r, y+r)
	{}
	void moveBarrelRight()
	{
		vec2.x += vec2.x * cos( M_PI * 0.12f ) - vec2.y*sin(M_PI * 0.12f);
		vec2.y += vec2.y * sin( M_PI * 0.12f ) + vec2.y *cos(M_PI * 0.12f) ;
	}
	void Draw(HDC hdc)
	{
		MoveToEx(hdc, vec.x, vec.y, NULL);
		LineTo(hdc,vec2.x, vec2.y);
	}
public:
	Vec2<float> vec; //x 
	Vec2<float> vec2; //x'
	float r;
};

