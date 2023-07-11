#include "gameuipanel.h"
#include <sstream>
#include "WorldState.h"

int WorldState::SCORE;
int WorldState::LIVES;

GameUIPanel::GameUIPanel(Vector2i res) :
    UIPanel(res,
            1,
            1,
            res.x / 3,
            res.y / 12,
            50, 255, 255,255) // a(lpha), r(ed), g(reen), b(lue)
{
    m_Text.setFillColor(Color(0, 255, 0, 255));
    m_Text.setString("Score: 0 Lives: 3 Wave: 1");
    m_Font.loadFromFile("fonts/Roboto-Bold.ttf");
    m_Text.setFont(m_Font);
    m_Text.setPosition(Vector2f(15, 15));
    m_Text.setCharacterSize(60);
}

void GameUIPanel::draw(RenderWindow &window)
{
    UIPanel::draw(window);
    std::stringstream ss;
    ss << "Score: " << WorldState::SCORE
       << " Lives: " << WorldState::LIVES
       << " Wave: " << WorldState::WAVE_NUMBER;
    m_Text.setString(ss.str());
    window.draw(m_Text);
}
