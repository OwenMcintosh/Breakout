#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "CONSTANTS.h"
#include "PowerupManager.h"

class GameManager;

class UI
{
public:
	UI(sf::RenderWindow* window, int lives, GameManager* gameManager);
	~UI();

	void update(float dt, std::pair<POWERUPS, float> powerup);

	void lifeLost(int lives);
	void HandleBarScale(float powerupTimeRemaining, sf::Color powerupColour);
	void render();

private:
	void updatePowerupText(std::pair<POWERUPS, float>);
	void screenShake(float dt);
	GameManager* _gameManager;
	
	sf::RenderWindow* _window;
	sf::Font _font;
	sf::Text _powerupText;
	sf::RectangleShape _powerupBarBackground;
	sf::RectangleShape _powerupBar;

	std::vector<sf::CircleShape> _lives;

	bool _screenIsShaking;
	float _screenShakeTimer;

	static constexpr float SCREEN_SHAKE_INTENSITY = 5.f;
	static constexpr float SCREEN_SHAKE_DURATION = 0.2f;

	static constexpr int8_t SCREEN_SHAKE_OFFSET_X_MAX = 100;
	static constexpr int8_t SCREEN_SHAKE_OFFSET_X_MIN = 50;

	static constexpr int8_t SCREEN_SHAKE_OFFSET_Y_MAX = 100;
	static constexpr int8_t SCREEN_SHAKE_OFFSET_Y_MIN = 50;

	static constexpr float DEFAULT_BAR_X = 100.f;
	static constexpr float DEFAULT_BAR_Y = 20.f;
	static constexpr float LIFE_RADIUS = 15.0f;
	static constexpr float LIFE_PADDING = 20.0f;
};

