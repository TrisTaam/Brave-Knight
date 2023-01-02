#pragma once
#include "SFML/Graphics.hpp"
#include "GameManager/ResourceManager.h"
#include "GameStateManager/GameStateMachine.h"

class Application {
public:
	void Run();
	~Application();
private:
	sf::RenderWindow* m_window;
	void Init();
	void Update(float deltaTime);
	void Render();
	sf::Image m_icon;
};