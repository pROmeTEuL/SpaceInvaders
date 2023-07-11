#include "gameinputhandler.h"
#include "soundengine.h"

void GameInputHandler::initialize()
{

}

void GameInputHandler::handleGamepad()
{

}

void GameInputHandler::handleKeyPressed(Event &event, RenderWindow &window)
{
    if (event.key.code == Keyboard::Escape) {
        SoundEngine::instance().playClick();
        getPointerToScreenManagerRemoteControl()->SwitchScreens("Select");
    }
}

void GameInputHandler::handleKeyReleased(Event &event, RenderWindow &window)
{

}
