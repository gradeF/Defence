#pragma once
#include "framework.h"
#include "Enemy.h"
#include "Gun_Barrel.h"
#include "Player.h"
#include "Vec2.h"
#include "Timer.h"
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
	void Move() //여기가 움직이는거
	{
		Vec2<float> temp = vec.Normalize( bar.Get_x(), bar.Get_y(), vec.x, vec.y );
 		vec.x = vec.x + temp.x * 10;
		vec.y = vec.y - temp.y * 10;
	}
	RECT GetRect() const
	{
		return { (long)(vec.x-r), (long)(vec.y - r) ,(long)(vec.x + r) ,(long)(vec.x + r) };
	}
private:
	Vec2<float> vec;
	float r = 10;//bullets의 좌표와 반지름
	float vel = 10.0f;
	barrel bar;
	Player p;
	Timer time;
};

