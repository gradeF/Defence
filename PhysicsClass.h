#pragma once
#include "Object.h"
#define _USE_MATH_DEFINES
#include <math.h>
class Move
{
public:
	Move()
	{
		en_X = enemy.GetX();
		en_Y = enemy.GetY();
	}
	Move(float x, float y)
		:
		en_X(x),
		en_Y(y)
	{}
	float DownValue()
	{
		return en_Y += en_Y * 9.8f;
	}
private:
	Enemy enemy;
	float en_X;
	float en_Y;
};
class Rotate
{
public:
	Rotate()
	{

	}
private:

};