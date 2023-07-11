#ifndef SCREENMANAGERREMOTECONTROL_H
#define SCREENMANAGERREMOTECONTROL_H

#include <string>
#include <vector>
//#include "gameobject.h"
//#include "gameobjectsharer.h"

using namespace std;

class ScreenManagerRemoteControl {
public:
    virtual void SwitchScreens(string screenToSwtichTo) = 0;
    virtual void loadLevelInPlayMode(string screenToLoad) = 0;
//    virtual vector<GameObject>& getGameObjects() = 0;
//    virtual GameObjectSharer& shareGameObjectsSharer() = 0;
};

#endif // SCREENMANAGERREMOTECONTROL_H
