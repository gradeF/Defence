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
	void Move()
	{
		center.y += 3.0f;
	}
	void CheckBullets(const Bullets& bullets, const Enemy& en)
	{
		const RECT bullet = bullets.GetRect();
		const RECT enemy = en.GetRect();
		if (bullet.left< enemy.right &&
			bullet.top < enemy.bottom &&
			bullet.right > enemy.left &&
			bullet.bottom > enemy.right)
		{

		}
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

