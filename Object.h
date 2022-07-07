#pragma once
#define _USE_MATH_DEFINES
#include "Vec2.h"
#include "framework.h"
#include <cmath>
#include <vector>
class Object 
{
public:
	Object()
		:
		center( 0.0f, 0.0f )
	{}
	Object(float x, float y)
		:
		center(x, y)
	{}
	Object(const Vec2<float>& center)
		:
		center(center)
	{}
	~Object() {}
	virtual void Draw(HDC hdc) const = 0;
protected:
	Vec2<float> center;
};
class player : public Object
{
public:
	player()
		:
		Object(),
		r(1)
	{}
	player(const Vec2<float> center, float r)
		:
		Object(),
		r(r)
	{}
	player(float x, float y, float r)
		:
		Object(x,y),
		r(r)
	{}
	~player() {}
	void Draw( HDC hdc ) const
	{
		Ellipse( hdc, (long)(center.x - r ), (long)(center.y - r), (long)(center.x + r), (long)(center.y + r));
	}

private:
	float r;
};
class wall : public Object
{
public:
	wall()
		:
		Object(),
		width(1),
		height(1),
		halfwidth(width * 0.5f),
		halfheight(height * 0.5f)
	{}
	wall (const Vec2<float> center, float width, float height)
		:
		Object(center),
		width(width),
		height(height),
		halfwidth(width * 0.5f),
		halfheight(height * 0.5f)
	{}
	wall(float x, float y, float width, float height)
		:
		Object(x,y),
		width(width),
		height(height),
		halfwidth(width * 0.5f),
		halfheight(height * 0.5f)
	{}
	RECT GetRect() const
	{
		return { (long)left, (long)top, (long)right, (long)bottom };
	}
	void Draw( HDC hdc ) const
	{
		for(int i=0;i<8;i++)
		{ 
			Rectangle( hdc, left+(i*width), top, right + (i * width), bottom );
		}
	}
private:
	float width;
	float height;
	float halfwidth;
	float halfheight;
	float left = center.x - halfwidth;
	float right = center.x + halfwidth;
	float top = center.y - halfheight;
	float bottom = center.y + halfheight;
	
};

class barrel : public Object
{
public:
	barrel()
		:
		Object(),
		point(0.0f, 0.0f),
		//temp(0.0f, 0.f),
		angle(M_PI*15.0f/180.0f),
		r(1)
	{}
	barrel(const Vec2<float>& center, Vec2<float> point, float r)
		:
		Object(center),
		point(point),
		//temp(point),
		angle(M_PI * 15.0f / 180.0f),
		r(r)
	{}
	barrel(float x, float y, float r)
		:
		Object(x, y),
		point(x + r, y - r),
		//temp(x+r, y-r),
		angle(M_PI * 15.0f / 180.0f),
		r(r)
	{}
	void Draw(HDC hdc) const
	{
		MoveToEx(hdc, center.x, center.y, NULL);
		LineTo(hdc, point.x, point.y);
	}
	void Rotate()
	{
		Vec2<float> temp = point - center;
		point.x = (temp.x * cos(angle)) - (temp.y * sin(angle)) + center.x;
		point.y = (temp.x * sin(angle)) + (temp.y * cos(angle)) + center.y;
	}
private:
	Vec2<float> point;
	float angle;
	float r;
	
};