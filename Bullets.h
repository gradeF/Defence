#pragma once
#include "framework.h"

#include "Vec2.h"
class Bullets
{
public:
	Bullets()
		:
		vec(0.0f, 0.0f)
	{}
	Bullets(float x, float y)
		:
		vec(x, y)
	{}
	~Bullets() {}
	void draw(HDC hdc)
	{
		Ellipse(hdc, vec.x - r, vec.y - r, vec.x + r, vec.y + r);
	}
private:
	Vec2<float> vec;
	float r = 10;//bullets의 좌표와 반지름
	float vel;

};

