#include "soundengine.h"

SoundEngine::SoundEngine()
{
    m_ShootBuffer.loadFromFile("sound/shoot.ogg");
    m_PlayerExplodeBuffer.loadFromFile("sound/playerexplode.ogg");
    m_InvaderExplodeBuffer.loadFromFile("sound/invaderexplode.ogg");
    m_ClickBuffer.loadFromFile("sound/click.ogg");

    m_ShootSound.setBuffer(m_ShootBuffer);
    m_PlayerExplodeSound.setBuffer(m_PlayerExplodeBuffer);
    m_InvaderExplodeSound.setBuffer(m_InvaderExplodeBuffer);
    m_ClickSound.setBuffer(m_ClickBuffer);
}

void SoundEngine::playShoot()
{
    m_ShootSound.play();
}

void SoundEngine::playPlayerExplode()
{
    m_PlayerExplodeSound.play();
}

void SoundEngine::playInvaderExplode()
{
    m_InvaderExplodeSound.play();
}

void SoundEngine::playClick()
{
    m_ClickSound.play();
}

SoundEngine &SoundEngine::instance()
{
    static SoundEngine se;
    return se;
}
