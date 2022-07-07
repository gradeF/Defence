#pragma once
#include "framework.h"
#include <random>
class Enemy
{
public:
	Enemy()
	{
		width = 40.0f;
		height = 40.0f;
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_real_distribution<float> RotateGen(RotateMin, RotateMax);
		x = RotateGen(rng);
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
	RECT GetRect() const
	{
		return { (long)(x - (width * 0.5f)), (long)(y - (height * 0.5f)), (long)(x + (width * 0.5f)), (long)(y + (height * 0.5f)) };
	}
	void Draw(HDC hdc)
	{
		Rectangle(hdc, x - (width * 0.5f), y - (height * 0.5f), x + (width * 0.5f), y + (height * 0.5f));
	}
	void Move()
	{
		y += 3.0f;
	}
private:
	float width;
	float height;
	float x, y;
	float RotateMin = 100.0f;
	float RotateMax = 400.0f;


};

