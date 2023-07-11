#include "screenmanager.h"

ScreenManager::ScreenManager(Vector2i res)
{
    m_Screens["Game"] = unique_ptr<GameScreen>(new GameScreen(this, res));
    m_Screens["Select"] = unique_ptr<SelectScreen>(new SelectScreen(this, res));
}

void ScreenManager::update(float fps)
{
    m_Screens[m_CurrentScreen]->update(fps);
}

void ScreenManager::draw(RenderWindow &window)
{
    m_Screens[m_CurrentScreen]->draw(window);
}

void ScreenManager::handleInput(RenderWindow &window)
{
    m_Screens[m_CurrentScreen]->handleInput(window);
}

void ScreenManager::SwitchScreens(string screenToSwitchTo)
{
    m_CurrentScreen = "" + screenToSwitchTo;
    m_Screens[m_CurrentScreen]->initialise();
}

void ScreenManager::loadLevelInPlayMode(string screenToLoad)
{
    //m_LevelManager.getGameObjects().clear();
    //m_LevelManager.loadGameObjectsForPlayMode(screenToLoad);
    SwitchScreens("Game");
}
