#ifndef STANDARDGRAPHICSCOMPONENT_H
#define STANDARDGRAPHICSCOMPONENT_H

#include "component.h"
#include "graphicscomponent.h"
#include <string>

class StandardGraphicsComponent : public GraphicsComponent
{
    Sprite m_sprite;
    string m_specificType = "standard";

    // Component interface
public:
    string getSpecificType() override;
    void start(GameObjectSharer *gos, GameObject *self) override;

    // GraphicsComponent interface
public:
    void draw(RenderWindow &window, std::shared_ptr<TransformComponent> t) override;
    void initializeGraphics(string bitmapName, Vector2f objectSize) override;
};

#endif // STANDARDGRAPHICSCOMPONENT_H
