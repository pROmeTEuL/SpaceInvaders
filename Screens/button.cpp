#include "button.h"

Button::Button(Vector2f position, float width, float height, unsigned int red, unsigned int green, unsigned int blue, std::string text)
{
    m_Button.setPosition(position);
    m_Button.setFillColor(Color(red, green, blue));
    m_Button.setSize(Vector2f(width, height));
    m_text = text;
    float textPaddingX = width / 10;
    float textPaddingY = height / 10;
    m_ButtonText.setCharacterSize(height * .7f);
    m_ButtonText.setString(text);
    m_Font.loadFromFile("fonts/Roboto-Bold.ttf");
    m_ButtonText.setFont(m_Font);
    m_ButtonText.setPosition(Vector2f(position.x + textPaddingX,
                                      position.y + textPaddingY));
    m_Collider = FloatRect(position, Vector2f(width, height));
}

void Button::draw(RenderWindow &window)
{
    window.draw(m_Button);
    window.draw(m_ButtonText);
}
