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
	float Get_x() const
	{
		return center.x;
	}
	float Get_y() const
	{
		return center.y;
	}
private:
	float r;
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
	void RotateRight()
	{
		
		Vec2<float> temp = point - center;
		point.x = (temp.x * cos(angle)) - (temp.y * sin(angle)) + center.x;
		point.y = (temp.x * sin(angle)) + (temp.y * cos(angle)) + center.y;
		if (point.y > 410)
		{
			point.y = 410;
			point.x = 621;
		}
	}
	float Get_point_x() const
	{
		return point.x;
	}
	float Get_point_y() const
	{
		return point.y;
	}
	float GetR() const
	{
		return r;
	}
	void RotateLeft()
	{
		
		Vec2<float> temp = point - center;
		point.x = (temp.x * cos( -angle )) - (temp.y * sin( -angle )) + center.x;
		point.y = (temp.x * sin( -angle )) + (temp.y * cos( -angle )) + center.y;
		if (point.y > 410)
		{
			point.y = 410;
			point.x = 399;
		}
	}
private:
	Vec2<float> point;
	float angle;
	float r;
	
};