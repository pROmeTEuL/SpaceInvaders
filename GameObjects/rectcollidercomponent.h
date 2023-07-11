#ifndef RECTCOLLIDERCOMPONENT_H
#define RECTCOLLIDERCOMPONENT_H

#include "collidercomponent.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class RectColliderComponent : public ColliderComponent
{
    string m_SpecificType = "rect";
    FloatRect m_Collider;
    string m_Tag = "";
public:
    RectColliderComponent(string name);
    string getColliderTag();
    void setOrMoveCollider(float x, float y, float width, float height);
    FloatRect& getColliderRectF();
    string getSpecificType() override;
    void start(GameObjectSharer* gos, GameObject* self) override;
};

#endif // RECTCOLLIDERCOMPONENT_H
