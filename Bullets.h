#pragma once
#include "framework.h"
#include "Enemy.h"
#include "Vec2.h"
#include "Timer.h"
class Bullets
{
public:
	Bullets()
		:
		vec(0.0f, 0.0f),
		dir(0.0f, 0.0f)
	{}
	Bullets(float x, float y , float dx, float dy)
		:
		vec( x , y ),
		dir( dx, dy )
	{}
	Bullets( const Vec2<float>& center, const Vec2<float> dir )
		:
		vec( center.x, center.y ),
		dir( dir.x, dir.y)
	{}
	~Bullets() {}
	void draw(HDC hdc) const
	{
		Ellipse(hdc, vec.x - r, vec.y - r, vec.x + r, vec.y + r);
	}
	void Move() //Here is for bullets to move
	{
 		vec.x = vec.x + dir.x * vel;
		vec.y = vec.y + dir.y * vel;
	}
	RECT GetRect() const
	{
		return { (long)(vec.x-r), (long)(vec.y - r) ,(long)(vec.x + r) ,(long)(vec.x + r) };
	}
private:
	Vec2<float> vec;
	Vec2<float> dir; //direction
	float r = 10; //Radius of bullet
	float vel = 10.0f; //velocity of bullet
};

