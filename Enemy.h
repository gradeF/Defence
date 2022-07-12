#pragma once
#include "framework.h"
#include "Bullets.h"
#include <random>
class Enemy
{
public:
	Enemy(float max)
	{
		std::random_device rd;
		std::mt19937 rng( rd() );
		std::uniform_real_distribution<float> gen_x(0.0f, max );
		center = { gen_x( rng ), 0.0f };
	}
	RECT GetRect() const
	{
		return { (long)(center.x - (width * 0.5f)), (long)(center.y - (height * 0.5f)), (long)(center.x + (width * 0.5f)), (long)(center.y + (height * 0.5f)) };
	}
	void Draw(HDC hdc) const
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
	bool IsAlive() const
	{
		return alive;
	}
	void Kill()
	{
		alive = false;
	}
private:
	
	static constexpr float speed = 100.0f;
	static constexpr float width = 40.0f;
	static constexpr float height = 40.0f;

private:
	Vec2<float> center;
	bool alive = true;

};

