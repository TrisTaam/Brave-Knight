#pragma once
#include "SFML/Graphics.hpp"
#include "GameStateMachine.h"
#include "../GameManager/ResourceManager.h"

class GameStateBase {
public:
	GameStateBase();
	virtual ~GameStateBase();
	virtual void Exit() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	static GameStateBase* CreateState(StateTypes st);
protected:
	std::list<GameButton*>* m_listBtn;
};