#pragma once
#include "../../GameManager/ResourceManager.h"
#include "../Player/IPlayer.h"
#include "../Bullet/Bullet.h"
#include <list>

class Gun {
public:
	Gun();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	sf::Vector2f GetPositon();
	int GetDame();
private:
	sf::Sprite* m_sprite;
	sf::Vector2f m_scale;
	float m_coolDown1;
	float m_coolDown2;
	float m_currentTime1;
	float m_currentTime2;
	int m_dame;
	bool m_autoFire;
};