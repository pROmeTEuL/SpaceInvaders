#ifndef SELECTSCREEN_H
#define SELECTSCREEN_H

#include "screen.h"

class SelectScreen : public Screen
{
    ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;
    Texture m_BackgroundTexture;
    Sprite m_BackgroundSprite;
public:
    SelectScreen(ScreenManagerRemoteControl* smrc, Vector2i res);
    virtual void draw(RenderWindow& window);
};

#endif // SELECTSCREEN_H
