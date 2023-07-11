#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "uipanel.h"
#include "ScreenManagerRemoteControl.h"

using namespace std;
class InputHandler;

class Screen
{
    vector<shared_ptr<InputHandler>> m_InputHandlers;
    vector<unique_ptr<UIPanel>> m_Panels;
protected:
    void addPanel(unique_ptr<UIPanel> p, ScreenManagerRemoteControl* smrc, shared_ptr<InputHandler> ih);
public:
    ~Screen();
    virtual void initialise();
    virtual void update(float fps);
    virtual void draw(RenderWindow& window);
    void handleInput(RenderWindow& window);
    View m_view;
};

#endif // SCREEN_H
