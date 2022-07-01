#pragma once
#include <vector>
#include "framework.h"


class Player {
private:
	float x;
	float y;
	float r = 100;
	RECT rect;
public:
	Player() {
		x = 0.0f;
		y = 0.0f;
	}
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
	float r = 200; //원의 중심에서의 거리
public:
	Gun_Barrel()
	{
		x = 640; //원에서 받아오게 만들기
		y = 712;

	}
	/*void setBarrel(float x, float y)
	{
		this->x = x;
		this->y = y;
	}*/
	void Draw(HDC hdc)
	{
		MoveToEx(hdc, x, y, NULL);
		LineTo(hdc, x, y-r);
	};
};
class Enemy
{
private:
public:
};

class Bullets
{
private:
	float x, y;//barrel의 끝이 기준점

public:
};
class Defence_Wall
{
private:
	int number=8;
	float x, y; //center
	float left;
	float right;
	float top;
	float bottom;
	float width;
	float height;
	float halfwidth;
	float halfheight;
public:
	Defence_Wall()
	{	
		x = 0;
		y = height - (height * 0.1f);
		width = right - left;
		height = bottom - top;
		halfwidth = width * 0.5f;
		halfheight = height * 0.5f;
	}
	void Draw(HDC hdc) 
	{
		
			Rectangle(hdc, left, top, right, bottom);
		
	}
	void Set_Wall(float x, float y,float width, float height) 
	{
		this->width = width;
		this->height = height;
		this->x = x;
		this->y = y;
		halfwidth = width * 0.5f;
		halfheight = height * 0.5f;

		left = x - halfwidth;
		right = x + halfwidth;
		top = y - halfheight;
		bottom = y + halfheight;


	}

};