#pragma once
#include "INotification.h"

class WaveNotification :public INotification {
public:
	WaveNotification();
	WaveNotification(float coolDown);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	Wave* m_wave;
};