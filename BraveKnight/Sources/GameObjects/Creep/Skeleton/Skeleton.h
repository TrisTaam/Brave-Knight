#pragma once
#include "../ICreep.h"

class Skeleton :public ICreep {
public:
	Skeleton();
	Skeleton(sf::Vector2f position, sf::Vector2i HP);
	~Skeleton();
	void ChangeNextState(ICState::STATE nextState);
	ICState::STATE GetState();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	sf::Vector2f GetScale();
private:
	void PerformStateChange();
	ICState::STATE m_nextState;
	ICState* m_currentState;
	ICState* m_runState;
	ICState* m_attackState;
	ICState* m_deathState;
	sf::Vector2f m_scale;
};