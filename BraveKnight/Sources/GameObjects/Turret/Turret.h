#pragma once
#include "../../GameManager/ResourceManager.h"
#include "../Component/HitBox/HitBox.h"

class Turret {
public:
	static int COST;
	static int NUM_TURRET;
	Turret();
	Turret(sf::Vector2f position);
	~Turret();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	HitBox* GetHitBox();
	sf::Vector2f GetPosition();
	Collider* GetCollider();
	int GetDame();
	void TakeDame(int dame);
	bool IsExplode();
	sf::Vector2i GetHP();
	sf::Vector2f GetScale();
private:
	sf::Vector2f m_position;
	HitBox* m_hitBox;
	sf::Sprite* m_sprite;
	sf::Vector2f m_scale;
	Collider* m_collider;
	Animation* m_animation;
	float m_radius;
	sf::CircleShape* m_circle;
	float m_curentTime;
	float m_coolDown;
	sf::Vector2i m_HP;
	int m_dame;
	bool m_isExplode;
	sf::RectangleShape* m_healthBar;
};