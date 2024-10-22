#include "AudioManager.h"

AudioManager::AudioManager() {

	addMusic("Audio/Music/Breakout.mp3", "music");
	
	addSound("Audio/SFX/ballHit.ogg", "hit");
	addSound("Audio/SFX/powerup.ogg", "powerup");
	addSound("Audio/SFX/fireHit.ogg", "fireHit");

}

AudioManager::~AudioManager()
{
	for (int i = 0; i < _soundVector.size(); i++) 
	{
		delete _soundVector[i];
	}

	for (int i = 0; i < _musicVector.size(); i++)
	{
		delete _musicVector[i];
	}
}

// given a sound file name, and it's respective use-case name, load and store a new soundFile struct object
void AudioManager::addSound(std::string fileName, std::string soundName)
{
	
	soundFile* newSound = new soundFile();

	if (!newSound->buffer.loadFromFile(fileName))
	{
		// Error...
		printf("error loading sound");
		delete newSound;
		return;
	}

	newSound->name = soundName;

	_soundVector.push_back(newSound);
}

// Play sound based on use-case name
void AudioManager::playSoundByName(std::string soundName)
{

	for (int i = 0; i < _soundVector.size(); i++) 
	{

		if (_soundVector[i]->name == soundName)
		{

			_soundToBePlayed.setBuffer(_soundVector[i]->buffer);
			_soundToBePlayed.play();

		}

	}

}

// given a music file name, and it's respective use-case name, load and store a new musicFile struct object
void AudioManager::addMusic(std::string fileName, std::string musicName)
{
	sf::Music music;
	if (!music.openFromFile(fileName))
	{
		// Error...
		return;
	}

	musicFile* newMusic = new musicFile();
	newMusic->name = musicName;
	newMusic->filename = fileName;

	_musicVector.push_back(newMusic);
}

void AudioManager::playMusicByName(std::string musicName)
{
	for (int i = 0; i < _musicVector.size(); i++)
	{

		if (_musicVector[i]->name == musicName)
		{

			_currentMusic.openFromFile(_musicVector[i]->filename);
			_currentMusic.setVolume(100);
			_currentMusic.play();
			_currentMusic.setLoop(true);

		}

	}



}

void AudioManager::FadeMusicOut(float dt) {

	if (_currentMusic.getVolume() - FADE_OUT_INTENSITY * dt <= 0.f) {
		_currentMusic.setVolume(0);
		return;
	}

	_currentMusic.setVolume(_currentMusic.getVolume() - FADE_OUT_INTENSITY * dt);
}

sf::Music* AudioManager::getCurrentMusic() { return &_currentMusic; }