#include "invaderupdatecomponent.h"
#include "bulletspawner.h"
#include "WorldState.h"
#include "soundengine.h"

void InvaderUpdateComponent::dropDownAndReverse()
{
    m_MovingRight = !m_MovingRight;
    m_TC->getLocation().y += m_TC->getSize().y;
    m_Speed += WorldState::WAVE_NUMBER + (WorldState::NUM_INVADERS_AT_START - WorldState::NUM_INVADERS) * m_SpeedModifier;
}

bool InvaderUpdateComponent::isMovingRight()
{
    return m_MovingRight;
}

void InvaderUpdateComponent::initializeBulletSpawner(BulletSpawner *bulletSpawner, int randSeed)
{
    m_BulletSpawner = bulletSpawner;
    m_RandSeed = randSeed;
    srand(m_RandSeed);
    m_TimeBetweenShots = rand() % 15 + m_RandSeed;
    m_AccuracyModifier = (rand() % 2);
    m_AccuracyModifier += static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 10);
}

string InvaderUpdateComponent::getSpecificType()
{
    return m_SpecificType;
}

void InvaderUpdateComponent::start(GameObjectSharer *gos, GameObject *self)
{
    m_PlayerTC = static_pointer_cast<TransformComponent>(gos->findFirstObjectWithTag("Player")
                                                             .getComponentByTypeAndSpecificType("transform", "transform"));
    m_PlayerRCC = static_pointer_cast<RectColliderComponent>(gos->findFirstObjectWithTag("Player")
                                                                 .getComponentByTypeAndSpecificType("collider", "rect"));
    m_TC = static_pointer_cast<TransformComponent>(self->getComponentByTypeAndSpecificType("transform", "transform"));
    m_RCC = static_pointer_cast<RectColliderComponent>(self->getComponentByTypeAndSpecificType("collider", "rect"));
}

void InvaderUpdateComponent::update(float fps)
{
    if (m_MovingRight) {
        m_TC->getLocation().x += m_Speed * fps;
    } else {
        m_TC->getLocation().x -= m_Speed * fps;
    }
    m_RCC->setOrMoveCollider(m_TC->getLocation().x, m_TC->getLocation().y, m_TC->getSize().x, m_TC->getSize().y);
    m_TimeSinceLastShoot += fps;
    if ((m_TC->getLocation().x + m_TC->getSize().x / 2) >
            (m_PlayerTC->getLocation().x - m_AccuracyModifier) &&
        (m_TC->getLocation().x + m_TC->getSize().x / 2) <
            (m_PlayerTC->getLocation().x + m_PlayerTC->getSize().x + m_AccuracyModifier)) {
        if (m_TimeSinceLastShoot > m_TimeBetweenShots) {
            SoundEngine::instance().playShoot();
            Vector2f spawnLocation;
            spawnLocation.x = m_TC->getLocation().x + m_TC->getSize().x / 2;
            spawnLocation.y = m_TC->getLocation().y + m_TC->getSize().y;
            m_BulletSpawner->spawnBullet(spawnLocation, false);
            srand(m_RandSeed);
            int mTimeBetweenShots = ((rand() % 10) + 1) / WorldState::WAVE_NUMBER;
            m_TimeSinceLastShoot = 0;
        }
    }
}
