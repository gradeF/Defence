#pragma once
#include "framework.h"
class Wall
{
public:
	Wall()
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
	Wall(float x, float y, float rectwidth, float rectheight)
		:
		x(x),
		y(y),
		rectwidth(rectwidth),
		rectheight(rectheight),
		halfwidth(rectwidth * 0.5f),
		halfheight(rectheight * 0.1f),
		width(halfwidth * 0.25f),
		height(halfheight)
	{
	}
	void Draw(HDC hdc) const
	{
		int x_in = x;
		for (int i = 0; i < 4; i++)
		{
			Rectangle(hdc, x_in, y, x_in + width, y + height);
			x_in += width;
		}
		x_in = x;
		for (int i = 0; i < 4; i++)
		{
			Rectangle(hdc, x_in - width, y, x_in + width, y + height);
			x_in -= width;
		}
	}
private:
	int number = 8;
	float x, y; //player center
	float rectwidth;
	float rectheight;
	float halfwidth; //rect halfwidth
	float halfheight; //not half, is divided 10.
	float width;
	float height;
};

