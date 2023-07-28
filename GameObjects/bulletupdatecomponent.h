#ifndef BULLETUPDATECOMPONENT_H
#define BULLETUPDATECOMPONENT_H

#include <memory>
#include "updatecomponent.h"
#include "transformcomponent.h"
#include "rectcollidercomponent.h"
#include "gameobject.h"
#include "gameobjectsharer.h"

class BulletUpdateComponent : public UpdateComponent
{
    string m_SpecificType = "bullet";
    shared_ptr<TransformComponent> m_TC;
    shared_ptr<RectColliderComponent> m_RCC;
    float m_Speed = 75.f;
    int m_AlienBulletSpeedModifier;
    int m_ModifierRandomComponent = 5;
    int m_MinimumAdditionalModifier = 5;
    bool m_MovingUp = true;
public:
    BulletUpdateComponent() = default;
    bool m_BelongsToPlayer = false;
    bool m_IsSpawned = false;
    void spawnForPlayer(Vector2f spawnPosition);
    void spawnForInvader(Vector2f spawnPosition);
    void deSpawn();
    bool isMovingUp();

    // Component interface
public:
    string getSpecificType() override;
    void start(GameObjectSharer *gos, GameObject *self) override;

    // UpdateComponent interface
public:
    void update(float fps) override;
};

#endif // BULLETUPDATECOMPONENT_H
