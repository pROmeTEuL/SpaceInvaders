#include "gameengine.h"

void GameEngine::input()
{
    m_ScreenManager->input(m_Window);
}

void GameEngine::update()
{
    m_ScreenManager->update(m_FPS);
}

void GameEngine::draw()
{
    m_Window.clear(Color::Black);
    m_ScreenManager->draw(m_Window);
    m_Window.display();
}

GameEngine::GameEngine()
{
    m_Resolution.x = VideoMode::getDesktopMode().width;
    m_Resolution.y = VideoMode::getDesktopMode().height;
    m_Window.create(VideoMode(m_Resolution.x, m_Resolution.y), "Space Invders++", Style::Default);
    m_ScreenManager = std::unique_ptr<ScreenManager> (new ScreenManager(Vector2i(m_Resolution)));
}

void GameEngine::run()
{
    while (m_Window.isOpen()) {
        m_DT = m_Clock.restart();
        m_FPS = m_DT.asSeconds();
        input();
        update();
        draw();
    }
}
