#pragma once
#include "IAState.h"
#include "IArrow.h"

class ASNormal :public IAState {
public:
	ASNormal(IArrow* arrow);
	void Init();
	void Update(float deltaTime, float angle);
	void Render(sf::RenderWindow* window);
private:
	IArrow* m_arrow;
	Animation* m_animation;
};
