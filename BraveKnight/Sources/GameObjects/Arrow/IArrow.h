#pragma once
#include "IAState.h"
#include "../Component/HitBox/HitBox.h"

class IArrow {
public:
	virtual void ChangeNextState(IAState::STATE nextState) = 0;
	virtual HitBox* GetHitBox() = 0;
	virtual sf::Vector2f GetScale() = 0;
	virtual sf::Vector2f GetPosition() = 0;
	virtual float GetRadius() = 0;
private:
};