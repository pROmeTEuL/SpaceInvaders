#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include "component.h"
#include <iostream>

class ColliderComponent : public Component
{
    string m_type = "collider";
    bool m_enabled = false;
    // Component interface
public:
    string getType() override;
    void disableComponent() override;
    void enableComponent() override;
    bool enabled() override;
    void start(GameObjectSharer *gos, GameObject *self) override;
};

#endif // COLLIDERCOMPONENT_H
