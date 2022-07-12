#pragma once
#include "framework.h"
#include "Player.h"
#include "Main.h"
#include "Enemy.h"
#include "Bullets.h"
#include "Wall.h"
#include "FrameTimer.h"
#include <algorithm>

class GameManager
{
public:
    GameManager()
        :
        player(510, 410),
        bar(510,410, 80),
        walls(8)
    {
        for (int i = 0; i < 8; i++)
        {
            float width = 140.0f;
            walls[i] = { 70 + (width*i), 480, 140, 40 };
        }  
    }
    void Update()
    {
        KeyboardInput();
        float dt = frametimer.Mark(); //초 간격(deltaTime)
        gen_time += dt;

        if (gen_time >= 2.0f)
        {
            enemy.emplace_back( (float)clientRect.right );
            gen_time = 0.0f;
        }
        for (auto& e : enemy)
        {
            e.Move( dt );
            if (e.CheckBottom( clientRect ))
            {
                e.Kill();
            }
            for (auto& b : bullets)
            {
                if (e.CheckCollision( b.GetRect() ))
                {
                    e.Kill();
                    b.Kill();
                }
            }
            for (auto& w : walls)
            {
                if (e.CheckCollision( w.GetRect() ))
                {
                    e.Kill();

                    w.Damaged( 1 );

                }
            }
        }
        for (auto& e : bullets)
        {
            e.Move( dt );
            if (e.CheckBorder( clientRect )) //if(true)
            {
                e.Kill(); //alive comes false
            }
        }

        auto newend = std::remove_if( bullets.begin(), bullets.end(),
            []( Bullets b )
            {

                return !b.IsAlive();
            }
        );
        auto newendenemy = std::remove_if( enemy.begin(), enemy.end(),
            []( Enemy e )
            {

                return !e.IsAlive();
            }
        );
        auto newendwall = std::remove_if( walls.begin(), walls.end(),
            []( Wall w )
            {

                return !w.IsAlive();
            }
        );
        bullets.erase( newend, bullets.end() ); //제거
        enemy.erase( newendenemy, enemy.end() );
        walls.erase( newendwall, walls.end() );
    }
    void Draw(HDC hdc)
    {
        for (const auto& e : bullets)
        {
            e.draw( hdc );
        }
        for (const auto& e : walls)
        {
            e.DrawRect( hdc );
        }
        bar.Draw( hdc );

        player.Draw( hdc );

        for (const auto& e : enemy)
        {
            e.Draw( hdc );
        }

        if (who != NULL)
        {
            health -= 1;
            walls[who].Draw( hdc, health );
        }
    }
private:
    void KeyboardInput()
    {
        if (GetAsyncKeyState( VK_LEFT ) & 0x8000) //input key
        {
            bar.RotateLeft();
        }
        if (GetAsyncKeyState( VK_RIGHT ) & 0x8000)
        {
            bar.RotateRight();
        }
        if (GetAsyncKeyState( VK_SPACE ) & 0x8000)
        {
            const Vec2<float> center = { player.Get_x(), player.Get_y() };
            const Vec2<float> endpoint = { bar.Get_barrel_x(), bar.Get_barrel_y() };
            const Vec2<float> direction = (endpoint - center).Normalize();
            bullets.emplace_back( endpoint, direction );
        }
    }

public:
    RECT clientRect;

private:
    Player player;
    barrel bar;
    std::vector<Bullets> bullets;
    std::vector<Enemy> enemy;
    FrameTimer frametimer;
    std::vector<Wall> walls;

    int health = 3;
    bool check = false;
    int count = 0;
    int who = 0;
    float gen_time = 0;
};

