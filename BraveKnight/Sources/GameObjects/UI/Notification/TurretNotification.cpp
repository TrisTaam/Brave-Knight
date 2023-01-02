#include "TurretNotification.h"

TurretNotification::TurretNotification() {
}

void TurretNotification::Init() {
	setString("You don't have enough coin to build a turret");
	setFont(*ASSET->getFont("m5x7"));
}

void TurretNotification::Update(float deltaTime) {
	if (m_cnt) {
		setFillColor(sf::Color(getFillColor().r, getFillColor().g, getFillColor().b, getFillColor().a - 1));
		m_cnt--;
	}
	else {
		m_isDone = true;
	}
}

void TurretNotification::Render(sf::RenderWindow* window) {
	if (m_cnt) window->draw(*this);
}
