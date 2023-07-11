#ifndef GAMEOVERINPUTHANDLER_H
#define GAMEOVERINPUTHANDLER_H

#include "inputhandler.h"

class GameOverInputHandler : public InputHandler
{
public:
    void handleKeyPressed(Event& event, RenderWindow& window) override;
    void handleLeftClick(const std::string& buttonInteractedWith, RenderWindow& window) override;
};

#endif // GAMEOVERINPUTHANDLER_H
