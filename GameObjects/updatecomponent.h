#ifndef UPDATECOMPONENT_H
#define UPDATECOMPONENT_H

#include "component.h"

class UpdateComponent : public Component
{
    string m_Type = "update";
    bool m_Enabled = false;
public:
    UpdateComponent() = default;
    virtual void update(float fps) = 0;

    // Component interface
public:
    string getType() override;
    void disableComponent() override;
    void enableComponent() override;
    bool enabled() override;
};

#endif // UPDATECOMPONENT_H
