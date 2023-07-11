#ifndef COMPONENT_H
#define COMPONENT_H

//#include "gameobjectsharer.h"
#include <string>

using namespace std;

class GameObject;
class GameObjectSharer;

struct Component {
    virtual string getType() = 0;
    virtual string getSpecificType() = 0;
    virtual void disableComponent() = 0;
    virtual void enableComponent() = 0;
    virtual bool enabled() = 0;
    virtual void start(GameObjectSharer* gos, GameObject* self) = 0;
};

#endif // COMPONENT_H
