#pragma once
#include "Object.h"
#define _USE_MATH_DEFINES
#include <math.h>
class EnemyMove
{
public:
	EnemyMove()
	{
		en_X = enemy.GetX();
		en_Y = enemy.GetY();
	}
	EnemyMove(float x, float y)
		:
		en_X(x),
		en_Y(y)
	{}
	float DownValue()
	{
		en_Y += en_Y * 9.8f;
	}
private:
	Enemy enemy;
	float en_X;
	float en_Y;
};