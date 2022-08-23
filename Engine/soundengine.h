#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include <SFML/Audio.hpp>

using namespace sf;

class SoundEngine
{
    SoundEngine();
    /// Buffers
    SoundBuffer m_ShootBuffer;
    SoundBuffer m_PlayerExplodeBuffer;
    SoundBuffer m_InvaderExplodeBuffer;
    SoundBuffer m_ClickBuffer;
    /// Sounds
    Sound m_ShootSound;
    Sound m_PlayerExplodeSound;
    Sound m_InvaderExplodeSound;
    Sound m_UhSound;
    Sound m_OhSound;
    Sound m_ClickSound;
    /// Players
    void playShoot();
    void playPlayerExplode();
    void playInvaderExplode();
    void playClick();

public:
    static SoundEngine &instance();
};

#endif // SOUNDENGINE_H
