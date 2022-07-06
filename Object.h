#pragma once
#include "Vec2.h"
#include "framework.h"
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
	void Draw( HDC hdc ) const
	{
		Rectangle( hdc, left, top, right, bottom );
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
		point( 0.0f, 0.0f ),
		r( 1 )
	{}
	barrel( const Vec2<float>& center, Vec2<float> point, float r )
		:
		Object( center ),
		point( point ),
		r( r )
	{}
	barrel( float x, float y, float r )
		:
		Object( x, y ),
		point( x+r, y-r ),
		r( r )
	{}
	void Draw( HDC hdc ) const
	{
		MoveToEx( hdc, center.x, center.y, NULL );
		LineTo( hdc, point.x, point.y );
	}
private:
	Vec2<float> point;
	float r;
};