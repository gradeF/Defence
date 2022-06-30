#pragma once
#include <vector>
#include "framework.h"

class Object
{
private:
	float winSizeX;
	float winSizeY;
public:
	Object();

};
class Player : public Object
{
private:
	float x;
	float y;
	float r;
public:
	void DrawCircle();

};
class Gun_Barrel :public Object
{
private:
public:
};
class Enemy:public Object
{
private:
public:
};

class Bullets :public Object
{
private:
public:
};
class Defence_Wall :public Object
{
private:
	int number;
	float left;
	float right;
	float top;
	float bottom;
public:
	void Draw(float, int, int);

};