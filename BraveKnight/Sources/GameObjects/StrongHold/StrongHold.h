#pragma once
#include "../../GameManager/ResourceManager.h"
#include "../Component/HitBox/HitBox.h"

class StrongHold {
public:
	StrongHold();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	sf::Vector2f GetPosition();
	Collider* GetCollider();
	void TakeDame(int dame);
	sf::Vector2i GetHp();
private:
	HitBox* m_hitBox;
	sf::Sprite* m_sprite;
	sf::Vector2f m_scale;
	Collider* m_collider;
	sf::Vector2i m_HP;
	sf::RectangleShape* m_healthBar;
};