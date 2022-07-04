#pragma once
#include "Object.h"
#include <cmath>
class PhysicsClass
{
public:
	PhysicsClass()
	{
		barrelX = barrel.GetBarrleX();
		barrelY = barrel.GetBarrleY();
		barrelR = barrel.GetBarrleR();
		angle = 15;
	}
	PhysicsClass( float barrelX, float BarrelY, float barrelR )
		:
		barrelX(barrel.GetBarrleX()),
		barrelY(barrel.GetBarrleY()),
		barrelR(barrel.GetBarrleR()),
		angle(15)
	{}

private:
	Gun_Barrel barrel;
	float barrelX;
	float barrelY;
	float barrelR;
	float angle;
};

