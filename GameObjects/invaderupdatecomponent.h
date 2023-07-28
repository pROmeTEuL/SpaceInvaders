#ifndef INVADERUPDATECOMPONENT_H
#define INVADERUPDATECOMPONENT_H

#include <memory>
#include "updatecomponent.h"
#include "transformcomponent.h"
#include "gameobjectsharer.h"
#include "rectcollidercomponent.h"
#include "gameobject.h"

#warning delete after BulletSpawner created
class BulletSpawner;

class InvaderUpdateComponent : public UpdateComponent
{
    string m_SpecificType = "invader";
    shared_ptr<TransformComponent> m_TC;
    shared_ptr<RectColliderComponent> m_RCC;
    shared_ptr<TransformComponent> m_PlayerTC;
    shared_ptr<RectColliderComponent> m_PlayerRCC;
    BulletSpawner* m_BulletSpawner;
    float m_Speed = 10.f;
    bool m_MovingRight = true;
    float m_TimeSinceLastShoot;
    float m_TimeBetweenShots = 5.f;
    float m_AccuracyModifier;
    float m_SpeedModifier = 0.05f;
    int m_RandSeed;
public:
    InvaderUpdateComponent() = default;
    void dropDownAndReverse();
    bool isMovingRight();
    void initializeBulletSpawner(BulletSpawner* bulletSpawner, int randSeed);

    // Component interface
public:
    string getSpecificType() override;
    void start(GameObjectSharer *gos, GameObject *self) override;

    // UpdateComponent interface
public:
    void update(float fps) override;
};

#endif // INVADERUPDATECOMPONENT_H
