#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "component.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class TransformComponent : public Component
{
    const string m_Type = "transform";
    Vector2f m_Location;
    float m_Height;
    float m_Width;
public:
    TransformComponent(float width, float height, Vector2f location);
    Vector2f& getLocation();
    Vector2f getSize();

    // Component interface
public:
    string getType() override;
    string getSpecificType() override;
    void disableComponent() override;
    void enableComponent() override;
    bool enabled() override;
    void start(GameObjectSharer *gos, GameObject *self) override;
};

#endif // TRANSFORMCOMPONENT_H
