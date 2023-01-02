#pragma once
#include "../../../GameManager/ResourceManager.h"
#include "../../Wave/Wave.h"

class INotification :public virtual sf::Text {
public:
	INotification();
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	bool IsDone();
protected:
	float m_coolDown;
	float m_currentTime;
	bool m_isDone;
	int m_cnt;
};