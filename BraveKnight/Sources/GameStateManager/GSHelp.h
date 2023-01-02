#pragma once
#include "GameStateBase.h"

class GSHelp :public GameStateBase {
public:
	GSHelp();
	~GSHelp();
	void Exit();
	void Pause();
	void Resume();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite* m_sprite;
	sf::Text* m_title;
	sf::Text* m_text;
};