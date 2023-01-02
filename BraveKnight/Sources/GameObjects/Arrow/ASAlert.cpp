#include "ASAlert.h"

ASAlert::ASAlert(IArrow* arrow) {
	m_arrow = arrow;
}

void ASAlert::Init() {
	m_animation = new Animation(*ASSET->getTexture("Arrow/Arrow_alert"), sf::Vector2i(2, 1), 0.5f);
	m_animation->setScale(m_arrow->GetScale());
}

void ASAlert::Update(float deltaTime, float angle) {
	sf::Vector2f playerPos = GConnector->GetPlayer()->GetHitBox()->getPosition();
	m_animation->setPosition(sf::Vector2f(playerPos.x + m_arrow->GetRadius() * cos(angle * PI / 180), playerPos.y + m_arrow->GetRadius() * sin(angle * PI / 180)));
	m_animation->setRotation(angle);
	m_animation->Update(deltaTime);
}

void ASAlert::Render(sf::RenderWindow* window) {
	window->draw(*m_animation);
}
