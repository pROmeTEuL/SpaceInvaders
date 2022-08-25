#ifndef UIPANNEL_H
#define UIPANNEL_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "button.h"

using namespace sf;
using namespace std;

class UIPannel
{
    RectangleShape m_UIPanel;
    bool m_Hidden = false;
    vector<shared_ptr<Button>> m_Buttons;
protected:
    float m_ButtonWidth = 0;
    float m_ButtonHeight = 0;
    float m_ButtonPadding = 0;

    Font m_Font;
    Text m_Text;

    void addButton(float x, float y, int width, int height,
                   int r /*red*/, int g /*green*/, int b /*blue*/, //rgb
                   string label);
public:
    View m_View;

    UIPannel(Vector2i res, int x, int y,
             float width, float height,
             int alpha /*opacity*/, int r /*red*/, int g /*green*/, int b /*blue*/); //(o)rgb
    vector<shared_ptr<Button>> getButtons();
    virtual void draw(RenderWindow& window);
    void show();
    void hide();
};

#endif // UIPANNEL_H
