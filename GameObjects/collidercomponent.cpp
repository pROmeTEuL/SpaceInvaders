#include "collidercomponent.h"

string ColliderComponent::getType()
{
    return m_type;
}

void ColliderComponent::disableComponent()
{
    m_enabled = false;
}

void ColliderComponent::enableComponent()
{
    m_enabled = true;
}

bool ColliderComponent::enabled()
{
    return m_enabled;
}

void ColliderComponent::start(GameObjectSharer *gos, GameObject *self)
{

}
