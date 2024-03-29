#include "selectuipanel.h"

void SelectUIPanel::initialiseButtons()
{
    addButton(m_ButtonPadding,
              m_ButtonPadding,
              m_ButtonWidth,
              m_ButtonHeight,
              0, 255, 0,
              "Play");
    addButton(m_ButtonPadding * 2 + m_ButtonWidth,
              m_ButtonPadding,
              m_ButtonWidth,
              m_ButtonHeight,
              255, 0, 0,
              "Quit");
}

SelectUIPanel::SelectUIPanel(Vector2i res) :
    UIPanel(res,
            (res.x / 10) * 2,
            res.y / 3,
            (res.x / 10) * 6,
            res.y / 3,
            50, 255, 255, 255) // a(lpha), r(ed), g(reen), b(lue)
{
    m_ButtonWidth = res.x / 20;
    m_ButtonHeight = res.y / 20;
    m_ButtonPadding = res.x / 100;
    m_Text.setFillColor(Color(0, 255, 0, 255));
    m_Text.setString("SPACE INVADERS ++");
    m_Font.loadFromFile("fonts/Roboto-Bold.ttf");
    m_Text.setFont(m_Font);
    m_Text.setPosition(Vector2f(m_ButtonPadding, m_ButtonHeight + m_ButtonPadding * 2));
    m_Text.setCharacterSize(160);
    initialiseButtons();
}

void SelectUIPanel::draw(RenderWindow &window)
{
    show();
    UIPanel::draw(window);
    window.draw(m_Text);
}
