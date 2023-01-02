#pragma once
#include "IPState.h"
#include "IPlayer.h"

class PSRun :public IPState {
public:
	PSRun(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	IPlayer* m_player;
	Animation* m_animation;
};
