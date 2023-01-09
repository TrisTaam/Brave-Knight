#pragma once
#include "INotification.h"

class GeneralNotification :public INotification {
public:
	GeneralNotification();
	GeneralNotification(string notification, float coolDown);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
};