#ifndef SELECTUIPANEL_H
#define SELECTUIPANEL_H

#include "uipanel.h"

class SelectUIPanel : public UIPanel
{
    void initialiseButtons();
public:
    SelectUIPanel(Vector2i res);
    virtual void draw(RenderWindow& window);
};

#endif // SELECTUIPANEL_H
