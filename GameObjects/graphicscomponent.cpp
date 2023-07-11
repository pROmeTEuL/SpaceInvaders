#include "graphicscomponent.h"

string GraphicsComponent::getType()
{
    return m_type;
}

void GraphicsComponent::disableComponent()
{
    m_enabled = false;
}

void GraphicsComponent::enableComponent()
{
    m_enabled = true;
}

bool GraphicsComponent::enabled()
{
    return m_enabled;
}

void GraphicsComponent::start(GameObjectSharer *gos, GameObject *self)
{

}
