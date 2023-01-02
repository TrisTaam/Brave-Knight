#pragma once
#include "IPState.h"
#include "IPlayer.h"

class PSIdle :public IPState{
public:
	PSIdle(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	IPlayer* m_player;
	Animation* m_animation;
};
