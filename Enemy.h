#pragma once
#include "framework.h"
#include "Bullets.h"
#include <random>
class Enemy
{
public:
	Enemy()
		:
		width(0.0f),
		height(0.0f),
		center(0.0f,0.0f)
	{}
	Enemy(float width, float height, const Vec2<float>&center)
		:
		width(width),
		height(height),
		center(center)
	{}
	RECT GetRect() const
	{
		return { (long)(center.x - (width * 0.5f)), (long)(center.y - (height * 0.5f)), (long)(center.x + (width * 0.5f)), (long)(center.y + (height * 0.5f)) };
	}
	void Draw(HDC hdc)
	{
		Rectangle(hdc, center.x - (width * 0.5f), center.y - (height * 0.5f), center.x + (width * 0.5f), center.y + (height * 0.5f));
	}

	void Move( float dt )
	{
		center.y += speed * dt;
	}
	bool CheckCollision(const RECT rect)
	{	
		const RECT thisR = GetRect();
		return (rect.left<  thisR.right&&
			rect.top < thisR.bottom&&
			rect.right > thisR.left&&
			rect.bottom > thisR.top);
	}
	bool CheckBottom(const RECT winR)
	{
		const RECT thisR = GetRect();
		return (thisR.bottom > winR.bottom);
	}
private:
	static constexpr float gen_x_min = 100.0f;
	static constexpr float gen_x_max = 400.0f;
	static constexpr float speed = 10.0f;

private:
	float width;
	float height;
	Vec2<float> center;
	bool alive = true;
};

