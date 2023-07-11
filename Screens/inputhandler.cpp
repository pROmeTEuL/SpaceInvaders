#include "inputhandler.h"
#include "screen.h"
#include <sstream>
#include <iostream>


void InputHandler::initialieseInputHandler(ScreenManagerRemoteControl *sw, vector<shared_ptr<Button> > buttons, View *pointerToUIView, Screen *parentScreen)
{
    m_ScreenManagerRemoteControl = sw;
    m_Buttons = buttons;
    m_PointerToUIPanelView = pointerToUIView;
    m_ParentScreen = parentScreen;
}

void InputHandler::handleInput(RenderWindow &window, Event &event)
{
    if (event.type == Event::KeyPressed) {
        handleKeyPressed(event, window);
    }

    if (event.type == Event::KeyReleased) {
        handleKeyReleased(event, window);
    }

    if (event.type == Event::MouseButtonReleased) {
        for (auto& it : m_Buttons) {
            const auto pp = window.mapPixelToCoords(Mouse::getPosition(), *getPointerToUIView());
            std::cout << "x:"<< pp.x<< ", y:"<< pp.y << std::endl;
            if (it->m_Collider.contains(pp)) {
                handleLeftClick(it->m_text, window);
                break;
            }
        }
    }
    handleGamepad();
}

void InputHandler::handleGamepad()
{

}

void InputHandler::handleKeyPressed(Event &event, RenderWindow &window)
{

}

void InputHandler::handleKeyReleased(Event &event, RenderWindow &window)
{

}

void InputHandler::handleLeftClick(const string &buttonInteractWith, RenderWindow &window)
{

}

View *InputHandler::getPointerToUIView()
{
    return m_PointerToUIPanelView;
}

ScreenManagerRemoteControl *InputHandler::getPointerToScreenManagerRemoteControl()
{
    return m_ScreenManagerRemoteControl;
}

Screen *InputHandler::getPointerToScreen()
{
    return m_ParentScreen;
}
