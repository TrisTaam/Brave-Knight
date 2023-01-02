#pragma once
#include "../ICState.h"
#include "../ICreep.h"

class SSAttack :public ICState {
public:
	SSAttack(ICreep* creep);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	ICreep* m_creep;
	Animation* m_animation;
};
