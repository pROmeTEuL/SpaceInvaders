#ifndef PLAYERUPDATECOMPONENT_H
#define PLAYERUPDATECOMPONENT_H

#include <memory>
#include "updatecomponent.h"
#include "transformcomponent.h"
#include "gameobjectsharer.h"
#include "rectcollidercomponent.h"
#include "gameobject.h"

class PlayerUpdateComponent : public UpdateComponent
{
    string m_SpecificType = "player";
    shared_ptr<TransformComponent> m_TC;
    shared_ptr<RectColliderComponent> m_RCC;
    float m_Speed = 50.f;
    float m_XExtern = 0;
    float m_YExtern = 0;
    bool m_IsHoldingLeft = false;
    bool m_IsHoldingRight = false;
    bool m_IsHoldingUp = false;
    bool m_IsHoldingDown = false;
public:
    void updateShipTravelWithController(float x, float y);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();

    // Component interface
public:
    string getSpecificType() override;
    void start(GameObjectSharer *gos, GameObject *self) override;

    // UpdateComponent interface
public:
    void update(float fps) override;
};

#endif // PLAYERUPDATECOMPONENT_H
