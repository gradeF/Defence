#pragma once
#include "framework.h"
#include "Enemy.h"
#include "Gun_Barrel.h"
#include "Object.h"
#include "Vec2.h"
class Bullets
{
public:
	Bullets()
		:
		vec(p.Get_x() + bar.GetR(), p.Get_y() + bar.GetR())
	{}
	Bullets(float x, float y)
		:
		vec(x + bar.GetR(), y + bar.GetR())
		
	{}
	Bullets(const Vec2<float>& center)
	{
		float x = bar.Get_point_x() + p.Get_x();
		float y = bar.Get_point_y() + p.Get_y(); 
	}
	~Bullets() {}
	void draw(HDC hdc)
	{
		Ellipse(hdc, vec.x - r, vec.y - r, vec.x + r, vec.y + r);
	}
	void Move()
	{
		vec.x = vec.x + vel;
		vec.y = vec.y - vel;
	}
private:
	Vec2<float> vec;
	float r = 10;//bullets의 좌표와 반지름
	float vel = 10.0f;
	barrel bar;
	player p;
};

