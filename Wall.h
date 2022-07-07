#pragma once
#include "framework.h"
#include "Vec2.h"
#include <vector>

class wall
{
public:
	wall()
		:
		center(0.0f, 0.0f),
		width( 1 ),
		height( 1 ),
		halfwidth( width * 0.5f ),
		halfheight( height * 0.5f )
	{
		points.resize( 4 );
		Setpoints();
	}
	wall( const Vec2<float> center, float width, float height )
		:
		center(center),
		width( width ),
		height( height ),
		halfwidth( width * 0.5f ),
		halfheight( height * 0.5f )
	{
		points.resize( 4 );
		Setpoints();
	}
	wall( float x, float y, float width, float height )
		:
		center(x,y),
		width( width ),
		height( height ),
		halfwidth( width * 0.5f ),
		halfheight( height * 0.5f )
	{
		points.resize( 4 );
		Setpoints();
	}
	RECT GetRect() const
	{
		return { (long)left, (long)top, (long)right, (long)bottom };
	}
	void Draw( HDC hdc ) const
	{
		Rectangle( hdc, left , top, right , bottom );
	}
	void Setpoints()
	{
		left = center.x - halfwidth;
		right = center.x + halfwidth;
		top = center.y - halfheight;
		bottom = center.y + halfheight;

		points[0] =  (center - Vec2<float>{left, top}) + center;
		points[1] = (center - Vec2<float>{right, top}) + center;
		points[2] = (center - Vec2<float>{right, bottom}) + center;
		points[3] = (center - Vec2<float>{left, bottom}) + center;

	}
private:
	Vec2<float> center;
	std::vector<Vec2<float>> points;
	float width;
	float height;
	float halfwidth;
	float halfheight;
	float left;
	float right;
	float top;
	float bottom ;

};

