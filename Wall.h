#pragma once
#include "framework.h"
#include "Vec2.h"
#include <vector>

class Wall
{
public:

	Wall(std::vector<Vec2<float>>& center, float width, float height)
		:
		center(center),
		width(width),
		height(height),
		halfwidth(width * 0.5f),
		halfheight(height * 0.5f)
	{

	}
	void Draw(HDC hdc)
	{
		for (int i = 0; i < 8; i+=width)
		{
			Rectangle(hdc, center[i].x-halfwidth,center[i].y-halfheight, center[i].x + halfwidth, center[i].y+halfheight);
		}
	}
private:
	std::vector<Vec2<float>>& center;
	float width;
	float height;
	float halfwidth;
	float halfheight;
};

