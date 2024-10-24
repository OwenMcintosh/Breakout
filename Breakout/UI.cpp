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

	_screenIsShaking = false;
	_screenShakeTimer = SCREEN_SHAKE_DURATION;
}

UI::~UI()
{
}

void UI::update(float dt, std::pair<POWERUPS, float> powerup)
{

	updatePowerupText(powerup);

	if (_screenIsShaking) {
		screenShake(dt);
	}

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
	_screenIsShaking = true;
}

void UI::HandleBarScale(float powerupTimeRemaining, sf::Color powerupColour) {
	_powerupBar.setSize(sf::Vector2f((powerupTimeRemaining / 5.f) * _powerupBarBackground.getSize().x, _powerupBarBackground.getSize().y));
	_powerupBar.setFillColor(powerupColour);
}

void UI::screenShake(float dt)
{
	sf::View shakeView = _window->getView();

	if (_screenShakeTimer > 0.f) {

		float offsetX = (std::rand() % SCREEN_SHAKE_OFFSET_X_MAX - SCREEN_SHAKE_OFFSET_X_MIN) / (float)SCREEN_SHAKE_OFFSET_X_MIN * SCREEN_SHAKE_INTENSITY;
		float offsetY = (std::rand() % SCREEN_SHAKE_OFFSET_Y_MAX - SCREEN_SHAKE_OFFSET_Y_MIN) / (float)SCREEN_SHAKE_OFFSET_Y_MIN * SCREEN_SHAKE_INTENSITY;

		// apply offset to the default view of the window
		shakeView.setCenter(_window->getDefaultView().getCenter().x + offsetX, _window->getDefaultView().getCenter().y + offsetY);

		// set view to offset
		_window->setView(shakeView);

		// reduce remaining duration
		_screenShakeTimer -= dt;
		return;
	}

	// screen is still said to be shaking, but no more remaining duration
	if (_screenIsShaking) {

		// reset
		_window->setView(_window->getDefaultView());
		_screenIsShaking = false;
		_screenShakeTimer = SCREEN_SHAKE_DURATION;
	}

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