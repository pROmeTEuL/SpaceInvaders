#include "uipannel.h"

void UIPannel::addButton(float x, float y, int width, int height, int r, int g, int b, string label)
{

}

UIPannel::UIPannel(Vector2i res, int x, int y, float width, float height, int alpha, int r, int g, int b)
{
    m_UIPanel.setFillColor(Color(r, g, b, alpha));
    m_UIPanel.setSize(Vector2f(width, height));
    m_View.setSize(Vector2f(width, height));
}

void UIPannel::draw(RenderWindow &window)
{

}

void UIPannel::show()
{

}

void UIPannel::hide()
{

}
