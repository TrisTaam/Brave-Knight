#pragma once
#include "../../../GameManager/ResourceManager.h"

enum TAG {
	PLAYER,
	CREEP,
	STRONG_HOLD,
	TURRET,
	NOTHING,
};

class HitBox :public sf::RectangleShape {
public:
	HitBox();
	HitBox(sf::Vector2i size);
	~HitBox();
	void Init(sf::Vector2f velocity);
	void SetVelocity(sf::Vector2f velocity);
	sf::Vector2f GetVelocity();
	void SetAlive(bool alive);
	bool IsAlive();
	void SetTag(TAG tag);
	TAG GetTag();
private:
	sf::Vector2f m_velocity;
	bool m_isAlive;
	TAG m_tag;
};