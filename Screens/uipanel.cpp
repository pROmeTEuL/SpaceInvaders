#include "uipanel.h"

void UIPanel::addButton(float x, float y, int width, int height, unsigned int red, unsigned int green, unsigned int blue, string label)
{
     m_Buttons.push_back(make_shared<Button>(Vector2f(x, y),
                                            width, height,
                                            red, green, blue,
                                            label));
}

UIPanel::UIPanel(Vector2i res, int x, int y, float width, float height, unsigned int alpha, unsigned int red, unsigned int green, unsigned int blue)
{
    m_UIPanel.setFillColor(Color(red, green, blue, alpha));
    m_UIPanel.setSize(Vector2f(width, height));
    m_View.setSize(Vector2f(width, height));
    m_View.setCenter(width / 2, height / 2);
    float viewportStartX = 1.f / (res.x / x);
    float viewportStartY = 1.f / (res.y / y);
    float viewportSizeX = 1.f / (res.x / width);
    float viewportSizeY = 1.f / (res.y / height);
    m_View.setViewport(FloatRect(viewportStartX, viewportStartY, viewportSizeX, viewportSizeY));
}

vector<shared_ptr<Button> > UIPanel::getButtons()
{
    return m_Buttons;
}

void UIPanel::draw(RenderWindow &window)
{
    window.setView(m_View);
    if (!m_Hidden) {
        window.draw(m_UIPanel);
        for (auto& it : m_Buttons) {
            it->draw(window);
        }
    }
}

void UIPanel::show()
{
    m_Hidden = false;
}

void UIPanel::hide()
{
    m_Hidden = true;
}
