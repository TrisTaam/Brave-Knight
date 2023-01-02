#pragma once
#pragma once
#include "../../GameManager/ResourceManager.h"
#include "../Player/IPlayer.h"

class IArrow;
class IAState {
public:
	enum STATE {
		STATE_NORMAL,
		STATE_ALERT,
		STATE_NULL,
	};
	virtual void Init() = 0;
	virtual void Update(float deltaTime, float angle) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
};