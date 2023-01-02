#include "ASNormal.h"

ASNormal::ASNormal(IArrow* arrow) {
	m_arrow = arrow;
}

void ASNormal::Init() {
	m_animation = new Animation(*ASSET->getTexture("Arrow/Arrow_normal"), sf::Vector2i(1, 1), 0.f);
	m_animation->setScale(m_arrow->GetScale());
}

void ASNormal::Update(float deltaTime, float angle) {
	sf::Vector2f playerPos = GConnector->GetPlayer()->GetHitBox()->getPosition();
	m_animation->setPosition(sf::Vector2f(playerPos.x + m_arrow->GetRadius() * cos(angle * PI / 180), playerPos.y + m_arrow->GetRadius() * sin(angle * PI / 180)));
	m_animation->setRotation(angle);
	m_animation->Update(deltaTime);
}

void ASNormal::Render(sf::RenderWindow* window) {
	window->draw(*m_animation);
}
