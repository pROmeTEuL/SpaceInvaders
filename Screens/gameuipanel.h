#ifndef GAMEUIPANEL_H
#define GAMEUIPANEL_H

#include "uipanel.h"

class GameUIPanel : public UIPanel
{
public:
    GameUIPanel(Vector2i res);
    void draw(RenderWindow& window) override;
};

#endif // GAMEUIPANEL_H
