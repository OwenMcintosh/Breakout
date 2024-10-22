#include "PowerupSmallBall.h"

PowerupSmallBall::PowerupSmallBall(sf::RenderWindow* window, Paddle* paddle, Ball* ball)
	: PowerupBase(window, paddle, ball)
{
	_sprite.setFillColor(smallBallEffectsColour); // Same colour as SmallPaddle
}

PowerupSmallBall::~PowerupSmallBall()
{
}

std::pair<POWERUPS, float> PowerupSmallBall::applyEffect()
{
	float timeLength = 5.f;
	_ball->setSizeChange(timeLength, sf::Vector2f(0.5, 0.5));
	return { ballSize, timeLength };
}
