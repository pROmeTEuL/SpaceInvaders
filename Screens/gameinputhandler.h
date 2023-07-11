#ifndef GAMEINPUTHANDLER_H
#define GAMEINPUTHANDLER_H

#include "inputhandler.h"

class GameScreen;

class GameInputHandler : public InputHandler
{
public:
    void initialize();
    void handleGamepad() override;
    void handleKeyPressed(Event& event, RenderWindow& window) override;
    void handleKeyReleased(Event& event, RenderWindow& window) override;
};

#endif // GAMEINPUTHANDLER_H
