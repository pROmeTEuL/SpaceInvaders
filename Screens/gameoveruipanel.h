#ifndef GAMEOVERUIPANEL_H
#define GAMEOVERUIPANEL_H

#include "uipanel.h"

class GameOverUIPanel : public UIPanel
{
    void initialiseButtons();
public:
    GameOverUIPanel(Vector2i res);
    void draw(RenderWindow& window) override;
};

#endif // GAMEOVERUIPANEL_H
