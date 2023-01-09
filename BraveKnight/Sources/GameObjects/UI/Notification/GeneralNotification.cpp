#include "GeneralNotification.h"

GeneralNotification::GeneralNotification() {
}

GeneralNotification::GeneralNotification(string notification, float coolDown) {
	setString(notification);
	m_coolDown = coolDown;
	m_currentTime = 0.f;
}

void GeneralNotification::Init() {
	setFont(*ASSET->getFont("m5x7"));
}

void GeneralNotification::Update(float deltaTime) {
	m_currentTime += deltaTime;
	if (m_currentTime >= m_coolDown / 255.f) {
		m_currentTime = 0.f;
		if (m_cnt) {
			setFillColor(sf::Color(getFillColor().r, getFillColor().g, getFillColor().b, getFillColor().a - 1));
			m_cnt--;
		}
		else {
			m_isDone = true;
		}
	}
}

void GeneralNotification::Render(sf::RenderWindow* window) {
	if (m_cnt) window->draw(*this);
}
