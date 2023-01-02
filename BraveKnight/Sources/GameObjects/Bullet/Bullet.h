#pragma once
#include "../../GameManager/ResourceManager.h"
#include "../Component/HitBox/HitBox.h"

class Bullet {
public:
	Bullet();
	~Bullet();
	Bullet(sf::Vector2f startPosition, float angle, float radius, int dame);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	Collider* GetCollider();
	HitBox* GetHitBox();
	Animation* GetAnimation();
	bool IsExplode();
	int GetDame();
private:
	HitBox* m_hitBox;
	Animation* m_animation;
	Animation* m_explode;
	sf::Vector2f m_scale;
	float m_angle;
	Collider* m_collider;
	bool m_isExplode;
	int m_dame;
	sf::Vector2f m_startPosition;
};