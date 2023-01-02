#include "Cursor.h"
#include "../Player/IPlayer.h"

Cursor::Cursor() {
	m_sprite = new sf::Sprite();
	m_scale = sf::Vector2f(0.3f, 0.3f);
}

void Cursor::Init() {
	m_sprite->setTexture(*ASSET->getTexture("Cursor/Cursor"));
	m_sprite->setOrigin(m_sprite->getTexture()->getSize().x / 2.f, m_sprite->getTexture()->getSize().y / 2.f);
	m_sprite->setColor(sf::Color::Red);
	m_sprite->setScale(m_scale);
}

void Cursor::Update(float deltaTime) {
	if (WConnector->IsFocus()) {
		WConnector->getWindow()->setMouseCursorVisible(false);
		sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(*WConnector->getWindow());
		sf::Vector2f playerPos = GConnector->GetPlayer()->GetHitBox()->getPosition();
		m_sprite->setPosition(sf::Vector2f(mousePos.x + playerPos.x - screenWidth / 2, mousePos.y + playerPos.y - screenHeight / 2));
	}
	else {
		WConnector->getWindow()->setMouseCursorVisible(true);
	}
}

void Cursor::Render(sf::RenderWindow* window) {
	window->draw(*m_sprite);
}

sf::Vector2f Cursor::GetPosition() {
	return m_sprite->getPosition();
}
