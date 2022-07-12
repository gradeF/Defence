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
		Ellipse(hdc, (int)(vec.x - r), (int)(vec.y - r), (int)(vec.x + r), (int)(vec.y + r));
	}
	void Move( float dt ) //Here is for bullets to move
	{
 		vec.x = vec.x + dir.x * vel * dt;
		vec.y = vec.y + dir.y * vel * dt;
	}
	RECT GetRect() const
	{
		return { (long)(vec.x-r), (long)(vec.y - r) ,(long)(vec.x + r) ,(long)(vec.x + r) };
	}
	bool CheckBorder(const RECT border) const
	{
		const RECT thisR = GetRect();
		return (thisR.left < border.left ||
				thisR.right> border.right ||
				thisR.top < border.top);
	}
	bool IsAlive() const
	{
		return alive;
	}
	void Kill() 
	{
		alive = false;
	}
private:
	Vec2<float> vec;
	Vec2<float> dir; //direction
	float r = 10; //Radius of bullet
	float vel = 100.0f; //velocity of bullet
	bool alive = true;
};

