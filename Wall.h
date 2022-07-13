#pragma once
#include "framework.h"
#include "Vec2.h"
#include "Enemy.h"
#include <vector>

class Wall
{
public:
	Wall()
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
	Wall( const Vec2<float> center, float width, float height )
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
	Wall( float x, float y, float width, float height )
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
	~Wall() {}
	RECT GetRect() const
	{
		return { (long)left, (long)top, (long)right, (long)bottom };
	}
	void DrawRect( HDC hdc) const
	{
		Rectangle( hdc, (int)left , (int)top, (int)right , (int)bottom );
	}
	void Draw(HDC hdc, const int health) 
	{
		DrawColorRect(hdc, health);
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
	void Damaged(const int damage)
	{
		health -= damage;
		if (health == 0)
		{
			alive = false;
		}
	}
	void DrawColorRect(HDC hdc, const int health)
	{
		HBRUSH hBrush, oldBrush;
		switch (health)
		{
		case 0:
			//destroyed wall when health is empty
			break;
		case 1:
			//Set Color Red
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			DrawRect(hdc);
			SelectObject(hdc, oldBrush);
			DeleteObject(hBrush);
			break;
		case 2:
			//Set Color Green
			hBrush = CreateSolidBrush(RGB(0, 255, 0));
			oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			DrawRect(hdc);
			SelectObject(hdc, oldBrush);
			DeleteObject(hBrush);
			break;
		case 3:
			DrawRect(hdc);
			break;
		}
	}
	bool IsAlive() const
	{
		return alive;
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
	float bottom;
	int health = 3;
	bool alive = true;
};

