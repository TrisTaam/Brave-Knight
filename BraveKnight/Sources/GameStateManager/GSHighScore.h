#pragma once
#include "GameStateBase.h"

class GSHighScore :public GameStateBase {
public:
	GSHighScore();
	~GSHighScore();
	void Exit();
	void Pause();
	void Resume();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite* m_sprite;
	sf::Text* m_text;
	sf::Text* m_title;
};