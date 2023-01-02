#pragma once
#include "../../GameManager/ResourceManager.h"
#include "IArrow.h"

class Arrow :public IArrow{
public:
	Arrow();
	~Arrow();
	void ChangeNextState(IAState::STATE nextState);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	HitBox* GetHitBox();
	sf::Vector2f GetScale();
	sf::Vector2f GetPosition();
	float GetRadius();
private:
	void PerformStateChange();
	HitBox* m_hitBox;
	IAState::STATE m_nextState;
	IAState* m_currentState;
	IAState* m_normalState;
	IAState* m_alertState;
	sf::Vector2f m_scale;
	float m_radius;
};