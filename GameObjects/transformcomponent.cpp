#include "transformcomponent.h"

TransformComponent::TransformComponent(float width, float height, Vector2f location)
{
    m_Height = height;
    m_Width = width;
    m_Location = location;
}

Vector2f &TransformComponent::getLocation()
{
    return m_Location;
}

Vector2f TransformComponent::getSize()
{
    return Vector2f(m_Width, m_Height);
}

string TransformComponent::getType()
{
    return m_Type;
}

string TransformComponent::getSpecificType()
{
    return m_Type;
}

void TransformComponent::disableComponent()
{

}

void TransformComponent::enableComponent()
{

}

bool TransformComponent::enabled()
{
    return false;
}

void TransformComponent::start(GameObjectSharer *gos, GameObject *self)
{

}
