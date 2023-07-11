#include "gameengine.h"

void GameEngine::handleInput()
{
    m_ScreenManager->handleInput(m_window);
}

void GameEngine::update()
{
    m_ScreenManager->update(m_FPS);
}

void GameEngine::draw()
{
    m_window.clear(Color::Black);
    m_ScreenManager->draw(m_window);
    m_window.display();
}

GameEngine::GameEngine()
{
    m_resolution.x = VideoMode::getDesktopMode().width;
    m_resolution.y = VideoMode::getDesktopMode().height;
    m_window.create(VideoMode(m_resolution.x, m_resolution.y), "Space Invaders++", Style::Fullscreen);
    m_ScreenManager = std::unique_ptr<ScreenManager>(new ScreenManager(Vector2i(m_resolution.x, m_resolution.y)));
}

void GameEngine::run()
{
    while (m_window.isOpen()) {
        m_dt = m_clock.restart();
        m_FPS = m_dt.asSeconds();
        handleInput();
        update();
        draw();
    }
}
