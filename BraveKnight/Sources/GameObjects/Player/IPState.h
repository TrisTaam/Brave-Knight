#pragma once
#include "../../GameManager/ResourceManager.h"
#include "../Cursor/Cursor.h"

class IPlayer;

class IPState {
public:
	enum STATE {
		STATE_IDLE,
		STATE_RUN,
		STATE_DEATH,
		STATE_NULL,
	};
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
};