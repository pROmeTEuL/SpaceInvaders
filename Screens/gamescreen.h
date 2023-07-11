#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screen.h"
#include "gameinputhandler.h"
#include "gameoverinputhandler.h"

class GameScreen : public Screen
{
    ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;
    shared_ptr<GameInputHandler> m_GIH;
    Texture m_BackgroundTexture;
    Sprite m_BackgroundSprite;
public:
    static bool m_GameOver;
    GameScreen(ScreenManagerRemoteControl* smrc, Vector2i res);
    void initialise() override;
    void update(float fps) override;
    void draw(RenderWindow& window) override;
};

#endif // GAMESCREEN_H
