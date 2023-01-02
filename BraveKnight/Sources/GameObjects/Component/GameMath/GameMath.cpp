#include "GameMath.h"

GameMath::GameMath() {
}

float GameMath::GetAngle(sf::Vector2f a, sf::Vector2f b) {
	float X = b.x - a.x;
	float Y = b.y - a.y;
	float angle = atan2(Y, X) * 180 / PI;
	return angle;
}

float GameMath::GetDistance(sf::Vector2f a, sf::Vector2f b) {
	float distance = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y,2));
	return distance;
}
