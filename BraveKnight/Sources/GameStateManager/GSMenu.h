#pragma once
#include "GameStateBase.h"

class GSMenu :public GameStateBase {
public:
	GSMenu();
	~GSMenu();
	void Exit();
	void Pause();
	void Resume();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_sprite;
	sf::Sprite m_titleSprite;
};