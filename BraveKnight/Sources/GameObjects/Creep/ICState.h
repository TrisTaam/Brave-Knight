#pragma once
#include "../../GameManager/ResourceManager.h"

class ICreep;

class ICState {
public:
	enum STATE {
		STATE_RUN,
		STATE_ATTACK,
		STATE_DEATH,
		STATE_NULL,
	};
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
};