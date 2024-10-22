# Breakout

W Kavanagh. June Summer 2024

## controls

A/D to move the paddle right and left.
P to pause.

## Powerups

big/small paddle (blue)
fast/slow ball (fancy yellow)
fire ball (green)

# Tasklist

## Suggested fixes

* Fix the compiler issues in the code

## Suggested tasks

* Implement mouse input for pad
* Improved VFX (ball trail, paddle hit response, brick particle destruction)
* Better UI (progress bar rather than timer for countdown).
* GameLoop
* Better ball physics (Box2D)
* Leaderboards
* More ball types (e.g., multiball, sticky ball [where you shoot the ball from the paddle every time], tiny ball, big ball, brick-tracking ball)
* Sounds with increasing tone between bounces.
* Implement commentary with calls to an LLM such as LLama

# Time Details and Changelist
20 minutes to familiarise with pre-existing codebase
10 minutes to fix circular dependency issue
20 minutes to add mouse movement to paddle
1 hour to add restart via any key/mouse press after loss via gamestate data distinctions
40 minutes to change ball effect display from text to bar
15 minutes to create new "smallBall" powerup effect
2 hours to create audio manager system and find suitable assets
10 minutes to create screen shake functionality upon life-loss
