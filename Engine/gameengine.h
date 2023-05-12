#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <memory>
#include <SFML/Graphics.hpp>
#include "screenmanager.h"
#include "soundengine.h"

using namespace sf;

class GameEngine
{
    Clock m_clock;
    Time m_dt;
    RenderWindow m_window;

    std::unique_ptr<ScreenManager> m_ScreenManager;
    float m_FPS = 0;
    Vector2f m_resolution;

    void handleInput();
    void update();
    void draw();
public:
    SoundEngine m_SoundEngine;
    GameEngine();
    void run();
};

#endif // GAMEENGINE_H
