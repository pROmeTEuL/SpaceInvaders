#include "updatecomponent.h"


string UpdateComponent::getType()
{
    return m_Type;
}

void UpdateComponent::disableComponent()
{
    m_Enabled = false;
}

void UpdateComponent::enableComponent()
{
    m_Enabled = true;
}

bool UpdateComponent::enabled()
{
    return m_Enabled;
}
