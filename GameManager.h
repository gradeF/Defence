#pragma once
#include "framework.h"
#include "Player.h"
#include "Main.h"
#include "Enemy.h"
#include "Bullets.h"
#include "Wall.h"
#include "FrameTimer.h"
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include "FileManager.h"

class GameManager
{
public:
    enum class GameMode
    {
        GameStart,
        MainGame,
        GameEnd
    };
public:
    GameManager()
        :
        player( 510, 410 ),
        bar( 510, 410, 80 ),
        walls( 8 ),
        fileManager( L"Ranking.txt" )
    {
        for (int i = 0; i < 8; i++)
        {
            float width = 140.0f;
            walls[i] = { 70 + (width*i), 480, 140, 40 };
        }  

        GetRankingFromData();
    }
    void Update()
    { 
        switch (mode)
        {
        case GameManager::GameMode::GameStart:
            break;
        case GameManager::GameMode::MainGame:
            {
                float dt = frametimer.Mark();
                if (startcheck)
                {
                     //?? ????(deltaTime)
                    KeyboardInput( dt );
                    GenerateEnemies( dt);
                    UpdateEnemies( dt );
                    UpdateBullet( dt );
                
                    EraseIf( bullets );
                    EraseIf( enemy );
                    EraseIf( walls );
                    if (walls.size() == 0)
                    {
                        mode = GameMode::GameEnd;
                    }
                }
                else
                {
                    InputStartKey();
                }
            }
            break;
        case GameManager::GameMode::GameEnd:
            break;
        }
    }

    void Draw(HDC hdc)
    {
        switch (mode)
        {
        case GameManager::GameMode::GameStart:
            break;
        case GameManager::GameMode::MainGame:
            {
                if (startcheck)
                {
                    HDC hMemDC;
                    HBITMAP hOldbitmap;
                    
                    hMemDC = CreateCompatibleDC( hdc );
                    if (hDoubleBufferImage == NULL)
                    {
                        hDoubleBufferImage = CreateCompatibleBitmap( hdc, clientRect.right, clientRect.bottom );
                    }
                    hOldbitmap = (HBITMAP)SelectObject( hMemDC, hDoubleBufferImage );

                    FillRect( hMemDC, &clientRect, (HBRUSH)GetStockObject( WHITE_BRUSH ) );

                    const std::wstring idStr = L"ID: " + playerID;
                    TextOut( hMemDC, 10, 10, idStr.c_str(), idStr.size() );
                    const std::wstring scoreStr = L"Score: " + std::to_wstring( score );
                    TextOut( hMemDC, 310, 10, scoreStr.c_str(), scoreStr.size() );

                    for (const auto& e : bullets)
                    {
                        e.draw( hMemDC );
                    }
                    for (const auto& e : walls)
                    {
                        e.DrawRect( hMemDC );
                    }
                    bar.Draw( hMemDC );

                    player.Draw( hMemDC );

                    for (const auto& e : enemy)
                    {
                        e.Draw( hMemDC );
                    }

                    if (who != NULL)
                    {
                        health -= 1;
                        walls[who].Draw( hMemDC, health );
                    }

                    BitBlt( hdc, 0, 0, clientRect.right, clientRect.bottom, hMemDC, 0, 0, SRCCOPY );
                    SelectObject( hMemDC, hOldbitmap );
                    DeleteObject( hMemDC );
                }
                else
                {
                    const std::wstring str = L"Press Enter to Start!";
                    TextOut( hdc, clientRect.right * 0.5 - 80, clientRect.bottom * 0.5, str.c_str(), str.size() );
                }
            }
            break;
        case GameManager::GameMode::GameEnd:
            break;
        }
    }

    void SetUserID( const std::wstring& id ) 
    {
        playerID = id;
    }
    std::wstring GetUserID() const
    {
        return playerID;
    }
    int GetScore() const
    {
        return score;
    }

    void SetGameModeMainGame()
    {
        mode = GameMode::MainGame;
    }
    bool IsGameEnd() const
    {
        return mode == GameMode::GameEnd;
    }

    auto GetRank() const
    {
        return rank;
    }

    void GetRankingFromData()
    {
        auto lines = fileManager.GetLineVector();

        for (const auto& line : lines)
        {
            auto pos = line.find( L" " );
            int scoreData = std::stoi( line.substr( pos, line.size() ) );
            const std::wstring nameData = line.substr( 0, pos );

            rank[scoreData].push_back( nameData );
        }
    }

    void SaveDataFromRank()
    {
        std::vector<std::wstring> lines;

        rank[score].push_back( playerID );

        for (auto it = rank.begin(); it != rank.end(); ++it)
        {
            for (const auto& str : it->second)
            {
                lines.push_back( str + L" " );
                lines.push_back( std::to_wstring( it->first ) + L"\n" );
            }
        }

        fileManager.SaveToFile( lines );
    }


private:
    void InputStartKey()
    {
        if (GetAsyncKeyState( VK_RETURN ) & 0x8000)
        {
            startcheck = true;
        }

    }
    void KeyboardInput(float dt)
    {
        bullet_gen_time += dt;

        if (GetAsyncKeyState( VK_LEFT ) & 0x8000) //input key
        {
            bar.RotateLeft(dt);
        }
        if (GetAsyncKeyState( VK_RIGHT ) & 0x8000)
        {
            bar.RotateRight(dt);
        }
        if (GetAsyncKeyState( VK_SPACE ) & 0x8000)
        {
            const Vec2<float> center = { player.Get_x(), player.Get_y() };
            const Vec2<float> endpoint = { bar.Get_barrel_x(), bar.Get_barrel_y() };
            const Vec2<float> direction = (endpoint - center).Normalize();
            if (bullet_gen_time >= 0.5f)
            {
               bullets.emplace_back( endpoint, direction );
               bullet_gen_time = 0.0f;
            }
        }
    }

    

    void GenerateEnemies(float dt)
    {
        enemy_gen_time += dt;
        if (enemy_gen_time >= 2.0f)
        {
            enemy.emplace_back( (float)clientRect.right );
            enemy_gen_time = 0.0f;
        }
    }
    void UpdateEnemies(float dt)
    {
        for (auto& e : enemy)
        {
            e.Move( dt );
            if (e.CheckBottom( clientRect ))
            {
                e.Kill();
                mode = GameMode::GameEnd;
            }
            for (auto& b : bullets)
            {
                if (e.CheckCollision( b.GetRect() ))
                {
                    e.Kill();
                    b.Kill();
                    score += 10;
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
    }
    void UpdateBullet( float dt )
    {
        for (auto& e : bullets)
        {
            e.Move( dt );
            if (e.CheckBorder( clientRect )) //if(true)
            {
                e.Kill(); //alive comes false
            }
        }
    }

    template<typename T>
    void EraseIf( std::vector<T>& container )
    {
        auto newEnd = std::remove_if( container.begin(), container.end(),
            []( T element )
            {
                return !element.IsAlive();
            }
        );
        container.erase( newEnd, container.end() );
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
    HBITMAP hDoubleBufferImage;
    GameMode mode = GameMode::GameStart;
    std::wstring playerID;
    std::map<int, std::vector<std::wstring>> rank;
    FileManager fileManager;

    int score = 0;
    int health = 3;
    bool startcheck = false;
    int count = 0;
    int who = 0;
    float enemy_gen_time = 0;
    float bullet_gen_time = 0;
};

