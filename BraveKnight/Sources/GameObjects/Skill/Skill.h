#pragma once
#include "../../GameManager/ResourceManager.h"

class Skill {
public:
	Skill();
	void Update(float deltaTime);
private:
	sf::Vector2f m_position;
	float m_currentTime;
	float m_coolDown;
	int m_cnt;
};