#include <sstream>

#include "UI.h"
#include "GameManager.h"
#include <iomanip>

UI::UI(sf::RenderWindow* window, int lives, GameManager* gameManager) 
	: _window(window), _gameManager(gameManager)
{
	for (int i = lives; i > 0; --i)
	{
		sf::CircleShape newLife;
		newLife.setFillColor(sf::Color::Red);	
		newLife.setOutlineColor(sf::Color::Cyan);
		newLife.setOutlineThickness(4.0f);
		newLife.setRadius(LIFE_RADIUS);
		newLife.setPosition((LIFE_RADIUS*2 + LIFE_PADDING) * i, LIFE_PADDING);
		_lives.push_back(newLife);
	}
	_powerupText.setCharacterSize(30);
	_powerupText.setPosition(790, 10);
	_powerupText.setFillColor(sf::Color::Cyan);
	_font.loadFromFile("font/montS.ttf");
	_powerupText.setFont(_font);

	_powerupBarBackground.setPosition(875, 20);
	_powerupBarBackground.setSize(sf::Vector2f(DEFAULT_BAR_X, DEFAULT_BAR_Y));
	_powerupBarBackground.setFillColor(sf::Color(0, 0, 0, 0));

	_powerupBar.setPosition(875, 20);
	_powerupBar.setSize(sf::Vector2f(DEFAULT_BAR_X, DEFAULT_BAR_Y));
	_powerupBar.setFillColor(sf::Color(0, 0, 0, 0));
}

UI::~UI()
{
}


void UI::updatePowerupText(std::pair<POWERUPS, float> powerup)
{
	std::ostringstream oss;
	_powerupBarBackground.setFillColor(sf::Color(144, 144, 144, 255));
	switch (powerup.first)
	{
	case bigPaddle:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("big");
		_powerupText.setFillColor(paddleEffectsColour);
		HandleBarScale(powerup.second, paddleEffectsColour);
		break;
	case smallPaddle:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("small");
		_powerupText.setFillColor(paddleEffectsColour);
		HandleBarScale(powerup.second, paddleEffectsColour);
		break;
	case slowBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("slow");
		_powerupText.setFillColor(ballEffectsColour);
		HandleBarScale(powerup.second, ballEffectsColour);
		break;
	case fastBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("fast");
		_powerupText.setFillColor(ballEffectsColour);
		HandleBarScale(powerup.second, ballEffectsColour);
		break;
	case fireBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("fire");
		_powerupText.setFillColor(extraBallEffectsColour);
		HandleBarScale(powerup.second, extraBallEffectsColour);
		break;
	case smallBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("scale");
		_powerupText.setFillColor(smallBallEffectsColour);
		HandleBarScale(powerup.second, smallBallEffectsColour);
		break;
	case none:
		_powerupText.setString("");
		_powerupBarBackground.setFillColor(sf::Color(0, 0, 0, 0));
		_powerupBar.setFillColor(sf::Color(0, 0, 0, 0));
		_powerupBar.setSize(_powerupBarBackground.getSize());
		break;
	}

}

void UI::lifeLost(int lives)
{
	_lives[_lives.size() - 1 - lives].setFillColor(sf::Color::Transparent);
}

void UI::HandleBarScale(float powerupTimeRemaining, sf::Color powerupColour) {
	_powerupBar.setSize(sf::Vector2f((powerupTimeRemaining / 5.f) * _powerupBarBackground.getSize().x, _powerupBarBackground.getSize().y));
	_powerupBar.setFillColor(powerupColour);
}

void UI::screenShake(sf::View& initialView)
{
	sf::View shakeView = initialView;
	
}

void UI::render()
{
	_window->draw(_powerupText);
	_window->draw(_powerupBarBackground);
	_window->draw(_powerupBar);
	for (sf::CircleShape life : _lives)
	{
		_window->draw(life);
	}
}