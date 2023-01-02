#pragma once
#include "SFML/Graphics.hpp"
#include "../../../GameConfig.h"
#include <math.h>

class GameMath {
public:
	GameMath();
	static float GetAngle(sf::Vector2f a, sf::Vector2f b);
	static float GetDistance(sf::Vector2f a, sf::Vector2f b);
};