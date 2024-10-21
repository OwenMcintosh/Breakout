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

	void updatePowerupText(std::pair<POWERUPS, float>);
	void lifeLost(int lives);
	void HandleBarScale(float powerupTimeRemaining, sf::Color powerupColour);
	void screenShake(sf::View& initialView);
	void render();

private:
	GameManager* _gameManager;
	
	sf::RenderWindow* _window;
	sf::Font _font;
	sf::Text _powerupText;
	sf::RectangleShape _powerupBarBackground;
	sf::RectangleShape _powerupBar;

	std::vector<sf::CircleShape> _lives;

	static constexpr float DEFAULT_BAR_X = 100.f;
	static constexpr float DEFAULT_BAR_Y = 20.f;
	static constexpr float LIFE_RADIUS = 15.0f;
	static constexpr float LIFE_PADDING = 20.0f;
};

