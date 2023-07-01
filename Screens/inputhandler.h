#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "button.h"
//#include "screen.h"
#include "ScreenManagerRemoteControl.h"

using namespace sf;
using namespace std;

class Screen;

class InputHandler
{
    Screen* m_ParentScreen;
    vector<shared_ptr<Button>> m_Buttons;
    View* m_PointerToUIPanelView;
    ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;
public:
    void initialieseInputHandler(
        ScreenManagerRemoteControl* sw,
        vector<shared_ptr<Button>> buttons,
        View* pointerToUIView,
        Screen* parentScreen);
    void handleInput(RenderWindow& window, Event& event);
    virtual void handleGamepad();
    virtual void handleKeyPressed(Event& event, RenderWindow& window);
    virtual void handleKeyReleased(Event& event, RenderWindow& window);
    virtual void handleLeftClick(string& buttonInteractWith, RenderWindow& window);
    View* getPointerToUIView();
    ScreenManagerRemoteControl* getPointerToScreenManagerRemoteControl();
    Screen* getPointerToScreen();
};

#endif // INPUTHANDLER_H
