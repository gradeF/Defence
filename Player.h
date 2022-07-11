#pragma once
#define _USE_MATH_DEFINES
#include "Vec2.h"
#include "framework.h"
#include <cmath>
#include <vector>
class Player
{
public:
	Player()
		:
		center( 0.0f, 0.0f )
	{}
	Player( float x, float y )
		:
		center( x, y )
	{}
	Player( const Vec2<float>& center )
		:
		center( center )
	{}
	~Player() {}
	void Draw( HDC hdc )
	{
		Ellipse( hdc, (long)(center.x - r), (long)(center.y - r), (long)(center.x + r), (long)(center.y + r) );
	}
	float Get_x() const
	{
		return center.x;
	}
	float Get_y() const
	{
		return center.y;
	}
protected:
	Vec2<float> center;
private:
	float r = 40;
};
class barrel : public Player
{
public:
	barrel()
		:
		Player(),
		point( 0.0f, 0.0f ),
		//temp(0.0f, 0.f),
		angle( M_PI * 15.0f / 180.0f ),
		r( 1 )
	{}
	barrel( const Vec2<float>& center, Vec2<float> point, float r )
		:
		Player( center ),
		point( point ),
		//temp(point),
		angle( M_PI * 15.0f / 180.0f ),
		r( r )
	{}
	barrel( float x, float y, float r )
		:
		Player( x, y ),
		point( x + r, y - r ),
		//temp(x+r, y-r),
		angle( M_PI * 15.0f / 180.0f ),
		r( r )
	{}
	void Draw( HDC hdc ) const
	{
		MoveToEx( hdc, center.x, center.y, NULL );
		LineTo( hdc, point.x, point.y );
	}
	void RotateRight()
	{

		Vec2<float> temp = point - center;
		point.x = (temp.x * cos( angle )) - (temp.y * sin( angle )) + center.x;
		point.y = (temp.x * sin( angle )) + (temp.y * cos( angle )) + center.y;
		if (point.y > 360)
		{
			point.y = 360;
			point.x = 624;
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
		if (point.y > 360)
		{
			point.y = 360;
			point.x = 399;
		}
	}
private:
	Vec2<float> point;
	float angle;
	float r;

};
