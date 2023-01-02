#include "StrongHold.h"
#include "../Map/Map.h"
#include "../../GameManager/CollisionManager.h"

StrongHold::StrongHold() {
	m_sprite = new sf::Sprite();
	m_scale = sf::Vector2f(4.f * globalScale.x, 4.f * globalScale.y);
	m_HP = sf::Vector2i(10000, 10000);
	m_healthBar = new sf::RectangleShape();
}

void StrongHold::Init() {
	m_hitBox = new HitBox(sf::Vector2i((strongHoldSize.x - 3) * m_scale.x, (strongHoldSize.y - 35) * m_scale.y));
	m_hitBox->setOrigin(m_hitBox->getSize() / 2.f);
	m_hitBox->setPosition(GConnector->GetMap()->GetMapSize() / 2.f);
	m_hitBox->SetTag(STRONG_HOLD);
	m_collider = new Collider(m_hitBox);
	m_sprite->setTexture(*ASSET->getTexture("StrongHold/Strong_hold"));
	m_sprite->setOrigin((strongHoldSize.x + 2) / 2.f, (strongHoldSize.y + 20) / 2.f);
	m_sprite->setPosition(m_hitBox->getPosition());
	m_sprite->setScale(m_scale);
	m_healthBar->setSize(sf::Vector2f(100.f, 10.f));
	m_healthBar->setFillColor(sf::Color::Red);
	m_healthBar->setPosition(m_hitBox->getPosition().x - 50.f, m_hitBox->getPosition().y + 50.f);
}

void StrongHold::Update(float deltaTime) {
	if (m_HP.x >= 0) {
		m_healthBar->setSize(sf::Vector2f(100.f * m_HP.x / m_HP.y, 10.f));
	}
	else {
		m_healthBar->setSize(sf::Vector2f(0.f * m_HP.x / m_HP.y, 10.f));
	}
}

void StrongHold::Render(sf::RenderWindow* window) {
	window->draw(*m_sprite);
	window->draw(*m_healthBar);
}

sf::Vector2f StrongHold::GetPosition() {
	return m_sprite->getPosition();
}

Collider* StrongHold::GetCollider() {
	return m_collider;
}

void StrongHold::TakeDame(int dame) {
	m_HP.x -= dame;
}

sf::Vector2i StrongHold::GetHp() {
	return m_HP;
}
