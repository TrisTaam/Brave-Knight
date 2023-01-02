#pragma once
#include "GameStateBase.h"

class GSIntro :public GameStateBase {
public:
	GSIntro();
	~GSIntro();
	void Exit();
	void Pause();
	void Resume();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite m_sprite;
	float m_currentTime;
	float m_coolDown;
	int m_cnt;
};