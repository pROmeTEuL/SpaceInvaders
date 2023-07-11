#include "selectinputhandler.h"
#include "soundengine.h"
#include "WorldState.h"
#include <iostream>

int WorldState::WAVE_NUMBER;

void SelectInputHandler::handleKeyPressed(Event &event, RenderWindow &window)
{
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }
}

void SelectInputHandler::handleLeftClick(const string &buttonInteractWith, RenderWindow &window)
{
    if (buttonInteractWith == "Play") {
        SoundEngine::instance().playClick();
        WorldState::WAVE_NUMBER = 0;
        getPointerToScreenManagerRemoteControl()->loadLevelInPlayMode("level1");
    }
    if (buttonInteractWith == "Quit") {
        SoundEngine::instance().playClick();
        window.close();
    }
}
