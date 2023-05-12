#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include <SFML/Graphics.hpp>
#include <map>
#include "gamescreen.h"
#include "screenmanagerremotecontrol.h"
#include "selectscreen.h"
//#include "levelmanager.h"
#include "bitmapstore.h"
#include <iostream>
#include <memory>

using namespace sf;
using namespace std;

class ScreenManager : public ScreenManagerRemoteControl
{
    map<string, unique_ptr<Screen>> m_Screens;
    //LevelManager m_LevelManager;
protected:
    string m_CurrentScreen = "Select";
public:
    ScreenManager(Vector2i res);
    BitmapStore m_BS;
    void update(float fps);
    void draw(RenderWindow& window);
    void handleInput(RenderWindow& window);
public:
    void ScreenManagerRemoteControl::SwitchScreens(string screenToSwitchTo)
    {
        m_CurrentScreen = "" + screenToSwitchTo;
        m_Screens[m_CurrentScreen]->initialise();
    }
    void ScreenManagerRemoteControl::loadLevelInPLayMode(string screenToLoad)
    {
        //m_LevelManager.getGameObjects().clear();
        //m_LevelManager.loadGameObjectsForPlayMode(screenToLoad);
        SwitchScreens("Game");
    }
    /*
     vector<GameObject>& ScreenManagerRemoteControl::getGameObjects()
    {
        return m_LevelManager.getGameObjects();
    }
    GameObjectSharer& shareGameObjectSharer()
    {
        return m_LevelManager;
    }
    */
};

#endif // SCREENMANAGER_H
