#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
//#include "gamescreen.h"
#include "Screens/screenmanagerremotecontrol.h"
//#include "selectscreen.h"
//#include "levelmanager.h"
#include "bitmapstore.h"

using namespace sf;
using namespace std;

class ScreenManager : public ScreenManagerRemoteControl
{
    map<string, unique_ptr<Screen>> m_Screens;
//    LevelManager m_LevelManager;
protected:
    string m_CurrentScreen = "Select";
public:
    BitmapStore m_BS;
    ScreenManager(Vector2i res);
    void update(float fps);
    void draw(RenderWindow& window);
    void handleInput(RenderWindow& window);
    ///From ScreenManagerRemoteControl interface:
    void SwitchScreens(string screenToSwitchTo) override {
        m_CurrentScreen = "" + screenToSwitchTo;
        m_Screens[m_CurrentScreen]->initialise();
    }
    void loadLevelInPlayMode(string screenToLoad) override {
        //m_LevelManager.getGameObjects().clear();
        //m_LevelManager.loadGameObjectsForPlayMode(screenToLoad);
        SwitchScreens("Game");
    }
    /*
    vector<GameObject>& ScreenManagerRemoteControl::getGameObjects() {
        return m_LevelManager.getGameObjects();
    }

    GameObjectSharer& shareGameObjectSharer() {
        return m_LevelManager;
    }
    */
};

#endif // SCREENMANAGER_H
