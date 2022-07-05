#pragma once
#define _USE_MATH_DEFINES
#include <vector>
#include "framework.h"
#include <random>
#include <math.h>

class Player {
private:
	float x;
	float y;
	float r; //50
	RECT rect;
public:
	Player()
	{
		x = 640;
		y = 712;
		r = 50.0f;
	}
	Player(float x, float y, float r)
		:
		x(x),
		y(y),
		r(r)
	{}
	~Player() {}
	void SetPlayer(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	void DrawPlayer(HDC hdc) {
		Ellipse(hdc, x - r, y - r, x + r, y + r);
	}

};
class Gun_Barrel
{
private:
	float x, y; //원의 중심
	float x1, y1;
	float r = 100;
	float angle = M_PI * 0.12f;//원의 중심에서의 거리
public:
	Gun_Barrel()
	{
		x = 640; //원에서 받아오게 만들기
		y = 712;
		x1 = x+r;
		y1 = y-r;

	}
	void SetbarrelX( float x )
	{
		x1 = x;
	}
	void SetBarrleY( float y )
	{
		y1 = y;
	}
	float GetBarrleX() const
	{
		return x;
	}
	float GetBarrleY() const
	{
		return y;
	}
	float GetBarrleR() const
	{
		return r;
	}
	void Draw( HDC hdc )
	{
		MoveToEx( hdc, x, y, NULL );
		LineTo( hdc, x1, y1 );
	}
	void RightMove()
	{
		x1 += r * cos( angle );
		y1 += r * sin( angle );
	}
	void LeftMove()
	{
		x1 += r * -cos( angle );
		y1 += r * -sin( angle );
	}
};
class Enemy
{
public:
	Enemy()
	{
		width = 120.0f;
		height = 120.0f;
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_real_distribution<float> RotateGen(RotateMin, RotateMax);
		x = RotateGen(rng);
		//x = 100.0f;
		y = 100.0f;
	}
	Enemy(float width, float height)
		:
		width(width),
		height(height)
	{
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_real_distribution<float> RotateGen(RotateMin, RotateMax);
		x = RotateGen(rng);
		//x = 100.0f;
		y = 100.0f;

	}
	float GetX() const
	{
		return x;
	}
	float GetY() const
	{
		return y;
	}
	void SetX(float x)
	{
		this->x = x;
	}
	void SetY(float y)
	{
		this->y = y;
	}
	void Draw(HDC hdc)
	{
		Rectangle(hdc, x - (width * 0.5f), y - (height * 0.5f), x + (width * 0.5f), y + (height * 0.5f));
	}
	void Move()
	{
		/*y += y * 9.8f;*/
		y += 3.0f;
	}
private:
	float width;
	float height;
	float x, y;

	float RotateMin = 100.0f;
	float RotateMax = 1300.0f;
};

class Bullets
{
private:
	float x, y, r=50;//bullets의 좌표와 반지름
	float b_x = 640;
	float b_y = 712;
	float b_r = 200;
public:
	Bullets()
	{
		this->x = b_x ;
		this->y = b_y - (b_r + r);
	}
	void draw(HDC hdc)
	{
		Ellipse(hdc, x-50, y-50,x+50, y+50 );
	}
};
class Defence_Wall
{
public:
	Defence_Wall()
	{
		x = 640;
		y = 712;
		rectwidth = 1440;
		rectheight = 712;
		halfwidth = rectwidth * 0.5f;
		halfheight = rectheight * 0.1f;
		width = halfwidth * 0.25f;
		height = halfheight;
	}
	Defence_Wall( float x, float y, float rectwidth, float rectheight )
		:
		x( x ),
		y( y ),
		rectwidth( rectwidth ),
		rectheight( rectheight ),
		halfwidth(rectwidth * 0.5f),
		halfheight(rectheight * 0.1f),
		width(halfwidth*0.25f),
		height(halfheight)
	{
	}
	void Draw( HDC hdc ) const
	{
		int x_in = x;
		for (int i = 0; i < 4; i++)
		{
			Rectangle( hdc, x_in, y, x_in + width, y + height );
			x_in += width;
		}
		x_in = x;
		for (int i = 0; i < 4; i++)
		{
			Rectangle( hdc, x_in - width, y, x_in + width, y + height );
			x_in -= width;
		}
	}
private:
	int number=8;
	float x, y; //player center
	float rectwidth;
	float rectheight;
	float halfwidth; //rect halfwidth
	float halfheight; //not half, is divided 10.
	float width;
	float height;
};