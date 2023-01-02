#pragma once
#include "SFML/Graphics.hpp"
#include "../HitBox/HitBox.h"

class Collider {
public:
	Collider();
	Collider(HitBox* hitBox);
	~Collider();
	void Move(float x, float y);
	bool CheckCollision(Collider* other);
	bool CheckCollision(Collider* other, float push);
	sf::Vector2f GetPosition();
	sf::Vector2f GetHalfSize();
	HitBox* GetHitBox();
private:
	HitBox* m_hitBox;
};