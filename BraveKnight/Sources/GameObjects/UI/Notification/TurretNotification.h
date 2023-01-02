#pragma once
#include "INotification.h"

class TurretNotification :public INotification {
public:
	TurretNotification();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
};