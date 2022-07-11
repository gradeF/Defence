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
		vec(0.0f, 0.0f),
		dir(bar.Get_x(), bar.Get_y())
	{}
	Bullets(float x, float y)
		:
		vec(x , y ),
		dir( bar.Get_x(), bar.Get_y() )
	{}
	Bullets(const Vec2<float>& center)
	{
		vec.x = center.x;
		vec.y = center.y;
		dir.x = bar.Get_x();
		dir.y = bar.Get_y();
	}
	~Bullets() {}
	void draw(HDC hdc) const
	{
		Ellipse(hdc, vec.x - r, vec.y - r, vec.x + r, vec.y + r);
	}
	void Move() //Here is for bullets to move
	{
 		vec.x = vec.x + dir.x * 10;
		vec.y = vec.y - dir.y * 10;
	}
	RECT GetRect() const
	{
		return { (long)(vec.x-r), (long)(vec.y - r) ,(long)(vec.x + r) ,(long)(vec.x + r) };
	}
private:
	Vec2<float> vec;
	Vec2<float> dir; //direction
	float r = 10;//bullets의 좌표와 반지름
	float vel = 10.0f;
	barrel bar;
	Player p;
};

