#include "bulletupdatecomponent.h"
#include "WorldState.h"

void BulletUpdateComponent::spawnForPlayer(Vector2f spawnPosition)
{
    m_MovingUp = true;
    m_BelongsToPlayer = true;
    m_IsSpawned = true;
    m_TC->getLocation().x = spawnPosition.x;
    m_TC->getLocation().y = spawnPosition.y - m_TC->getSize().y;
    m_RCC->setOrMoveCollider(m_TC->getLocation().x, m_TC->getLocation().y
                             m_TC->getSize().x, m_TC->getSize().y);
}

void BulletUpdateComponent::spawnForInvader(Vector2f spawnPosition)
{
    m_MovingUp = false;
    m_BelongsToPlayer = false;
    m_IsSpawned = true;
    m_TC->getLocation().x = spawnPosition.x;
    m_TC->getLocation().y = spawnPosition.y;
    m_RCC->setOrMoveCollider(m_TC->getLocation().x, m_TC->getLocation().y
                             m_TC->getSize().x, m_TC->getSize().y);
}

void BulletUpdateComponent::deSpawn()
{
    m_IsSpawned = false;
}

bool BulletUpdateComponent::isMovingUp()
{
    return m_MovingUp;
}

string BulletUpdateComponent::getSpecificType()
{
    return m_SpecificType;
}

void BulletUpdateComponent::start(GameObjectSharer *gos, GameObject *self)
{
    m_TC = static_pointer_cast<TransformComponent>(self->getComponentByTypeAndSpecificType("transform", "transform"));
    m_RCC = static_pointer_cast<RectColliderComponent>(self->getComponentByTypeAndSpecificType("collider", "rect"));
}

void BulletUpdateComponent::update(float fps)
{
    if (m_IsSpawned) {
        if (m_MovingUp) {
            m_TC->getLocation().y -= m_Speed * fps;
        } else {
            m_TC->getLocation().y += m_Speed * fps;
        }
        if (m_TC->getLocation().y > WorldState::WORLD_HEIGHT || m_TC->getLocation().y < -2) {
            deSpawn();
        }
        m_RCC->setOrMoveCollider(m_TC->getLocation().x, m_TC->getLocation().y
                                 m_TC->getSize().x, m_TC->getSize().y);
    }
}
