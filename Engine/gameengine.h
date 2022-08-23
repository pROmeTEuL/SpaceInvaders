#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include "screenmanager.h"
#include "soundengine.h"

using namespace sf;

class GameEngine
{
    Clock m_Clock;
    Time m_DT;
    RenderWindow m_Window;
    std::unique_ptr<ScreenManager> m_ScreenManager;
    float m_FPS = 0;
    Vector2f m_Resolution;
    void input();
    void update();
    void draw();
public:
    GameEngine();
    SoundEngine m_SoundEngine;
    void run();
};

#endif // GAMEENGINE_H
