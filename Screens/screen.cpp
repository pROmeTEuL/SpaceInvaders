#include "screen.h"


void Screen::addPanel(unique_ptr<UIPanel> p, ScreenManagerRemoteControl *smrc, shared_ptr<InputHandler> ih)
{
    ih->initialieseInputHandler(smrc, p->getButtons(), &p->m_View, this);
    m_Panels.push_back(move(p));
    m_InputHandlers.push_back(ih);
}

void Screen::initialise()
{

}

void Screen::update(float fps)
{

}

void Screen::draw(RenderWindow &window)
{
    for (auto& it : m_Panels) {
        it->draw(window);
    }
}

void Screen::handleInput(RenderWindow &window)
{
    Event event;
    while (window.pollEvent(event)) {
        for (auto& it : m_InputHandlers)
            it->handleInput(window, event);
    }
}
