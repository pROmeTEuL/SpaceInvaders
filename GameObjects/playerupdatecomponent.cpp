#include "playerupdatecomponent.h"
#include "WorldState.h"

void PlayerUpdateComponent::updateShipTravelWithController(float x, float y)
{
    m_XExtern = x;
    m_YExtern = y;
}

void PlayerUpdateComponent::moveLeft()
{
    m_IsHoldingLeft = true;
    stopRight();
}

void PlayerUpdateComponent::moveRight()
{
    m_IsHoldingRight = true;
    stopLeft();
}

void PlayerUpdateComponent::moveUp()
{
    m_IsHoldingUp  =true;
    stopDown();
}

void PlayerUpdateComponent::moveDown()
{
    m_IsHoldingDown = true;
    stopUp();
}

void PlayerUpdateComponent::stopLeft()
{
    m_IsHoldingLeft = false;
}

void PlayerUpdateComponent::stopRight()
{
    m_IsHoldingRight = false;
}

void PlayerUpdateComponent::stopUp()
{
    m_IsHoldingUp = false;
}

void PlayerUpdateComponent::stopDown()
{
    m_IsHoldingDown = false;
}

string PlayerUpdateComponent::getSpecificType()
{
    return m_SpecificType;
}

void PlayerUpdateComponent::start(GameObjectSharer *gos, GameObject *self)
{
    m_TC = static_pointer_cast<TransformComponent>(self->getComponentByTypeAndSpecificType("transform", "transform"));
    m_RCC = static_pointer_cast<RectColliderComponent>(self->getComponentByTypeAndSpecificType("collider", "rect"));
}

void PlayerUpdateComponent::update(float fps)
{
    if (Joystick::isConnected(0)) {
        m_TC->getLocation().x += (m_Speed / 100) * m_XExtern * fps;
        m_TC->getLocation().y += (m_Speed / 100) * m_YExtern * fps;
    }
    if (m_IsHoldingLeft) {
        m_TC->getLocation().x -= m_Speed * fps;
    } else if (m_IsHoldingRight) {
        m_TC->getLocation().x += m_Speed * fps;
    }
    if (m_IsHoldingUp) {
        m_TC->getLocation().y -= m_Speed * fps;
    } else if (m_IsHoldingDown) {
        m_TC->getLocation().y += m_Speed * fps;
    }
    m_RCC->setOrMoveCollider(m_TC->getLocation().x, m_TC->getLocation().y, m_TC->getSize().x, m_TC->getSize().y);
    if (m_TC->getLocation().x > WorldState::WORLD_WIDTH - m_TC->getSize().x) {
        m_TC->getLocation().x = WorldState::WORLD_WIDTH - m_TC->getSize().x;
    } else if (m_TC->getLocation().x < 0) {
        m_TC->getLocation().x = 0;
    }
    if (m_TC->getLocation().y > WorldState::WORLD_HEIGHT - m_TC->getSize().y) {
        m_TC->getLocation().y = WorldState::WORLD_HEIGHT - m_TC->getSize().y;
    } else if (m_TC->getLocation().y < WorldState::WORLD_HEIGHT / 2) {
        m_TC->getLocation().y = WorldState::WORLD_HEIGHT / 2;
    }
}
