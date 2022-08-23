#include "screenmanager.h"

ScreenManager::ScreenManager(Vector2i res)
{
    m_Screens["Game"] = unique_ptr<GameScreen>(new SelectScreen(this, res));
    m_Screens["Select"] = unique_ptr<SelectScreen>(new SelectScreen(this, res));
}
