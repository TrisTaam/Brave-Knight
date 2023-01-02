#pragma once
#include "../../GameManager/ResourceManager.h"

class Cursor {
public:
	Cursor();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow *window);
	sf::Vector2f GetPosition();
private:
	sf::Sprite* m_sprite;
	sf::Vector2f m_scale;
};