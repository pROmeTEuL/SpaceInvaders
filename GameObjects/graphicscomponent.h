#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

#include "component.h"
#include "transformcomponent.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

using namespace sf;
using namespace std;

class GraphicsComponent : public Component
{
    string m_type = "graphics";
    bool m_enabled = false;
public:
    virtual void draw(RenderWindow& window, shared_ptr<TransformComponent> t) = 0;
    virtual void initializeGraphics(string bitmapName, Vector2f objectSize) = 0;

    // Component interface
public:
    string getType() override;
    void disableComponent() override;
    void enableComponent() override;
    bool enabled() override;
    void start(GameObjectSharer *gos, GameObject *self) override;
};

#endif // GRAPHICSCOMPONENT_H
