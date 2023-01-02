#pragma once
#pragma once
#pragma once
#include "IAState.h"
#include "IArrow.h"

class ASAlert :public IAState {
public:
	ASAlert(IArrow* arrow);
	void Init();
	void Update(float deltaTime, float angle);
	void Render(sf::RenderWindow* window);
private:
	IArrow* m_arrow;
	Animation* m_animation;
};
