#include "selectscreen.h"
#include "selectuipanel.h"
#include "selectinputhandler.h"

SelectScreen::SelectScreen(ScreenManagerRemoteControl *smrc, Vector2i res)
{
    auto suip = make_unique<SelectUIPanel>(res);
    auto sih = make_shared<SelectInputHandler>();
    addPanel(move(suip), smrc, sih);
    m_ScreenManagerRemoteControl = smrc;
    m_BackgroundTexture.loadFromFile("graphics/background.png");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
    auto textureSize = m_BackgroundSprite.getTexture()->getSize();
    m_BackgroundSprite.setScale(float(m_view.getSize().x) / textureSize.x, float(m_view.getSize().y) / textureSize.y);
}

void SelectScreen::draw(RenderWindow &window)
{
    window.setView(m_view);
    window.draw(m_BackgroundSprite);
    Screen::draw(window);
}
