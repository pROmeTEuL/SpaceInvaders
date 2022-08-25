#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Button
{
    RectangleShape m_Button;
    Text m_ButtonText;
    Font m_Font;
public:
    std::string m_Text;
    FloatRect m_Collider;
    Button(Vector2f position,
           float width, float height,
           int r/*red*/, int g/*green*/, int b/*blue*/, //rgb
           std::string text);
    void draw(RenderWindow& window);
};

#endif // BUTTON_H
