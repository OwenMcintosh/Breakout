#pragma once
#include "SFML\Audio.hpp"

struct soundFile 
{
    sf::SoundBuffer buffer;
    std::string name;
};

struct musicFile 
{
    std::string filename;
    std::string name;
};

class AudioManager
{

public:
    AudioManager();
    ~AudioManager();

    void addSound(std::string fileName, std::string soundName);
    void playSoundByName(std::string fileName);

    void addMusic(std::string fileName, std::string musicName);
    void playMusicByName(std::string musicName);

    void FadeMusicOut(float dt);

    sf::Music* getCurrentMusic();
private:
    std::vector<soundFile*> _soundVector;
    std::vector<musicFile*> _musicVector;

    sf::Sound _soundToBePlayed;
    sf::Music _currentMusic;

    static float constexpr FADE_OUT_INTENSITY = 15.f;
};