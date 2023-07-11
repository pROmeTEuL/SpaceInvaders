#ifndef SELECTINPUTHANDLER_H
#define SELECTINPUTHANDLER_H

#include "inputhandler.h"

class SelectInputHandler : public InputHandler
{
public:
    void handleKeyPressed(Event &event, RenderWindow &window) override;
    void handleLeftClick(const string &buttonInteractWith, RenderWindow &window) override;
};

#endif // SELECTINPUTHANDLER_H
