#include "Gun.h"
#include <cmath>
#include "../Cursor/Cursor.h"

Gun::Gun() {
	m_scale = sf::Vector2f(2.f * globalScale.x, 2.f * globalScale.y);
	m_sprite = new sf::Sprite();
	m_coolDown = 0.1f;
	m_currentTime = 0.f;
	m_dame = 50;
}

void Gun::Init() {
	m_sprite->setTexture(*ASSET->getTexture("Gun/Gun"));
	m_sprite->setScale(m_scale);
}

void Gun::Update(float deltaTime) {
	m_currentTime += deltaTime;
	if (WConnector->IsFocus()) {
		sf::Vector2f cursorPos = GConnector->GetCursor()->GetPosition();
		sf::Vector2f handPos = sf::Vector2f(GConnector->GetPlayer()->GetHitBox()->getPosition().x + 10 * GConnector->GetPlayer()->GetFaceDir(), GConnector->GetPlayer()->GetHitBox()->getPosition().y + 15);
		m_sprite->setPosition(handPos);
		m_sprite->setOrigin(10, 5);
		m_sprite->setScale(m_scale.x, fabs(m_scale.y) * GConnector->GetPlayer()->GetFaceDir());
		float angle = GameMath::GetAngle(handPos, cursorPos);
		m_sprite->setRotation(angle);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (m_currentTime >= m_coolDown) {
				m_currentTime = 0;
				GConnector->GetListBullet()->push_back(new Bullet(GetPositon(), GameMath::GetAngle(handPos, cursorPos), 40.f, m_dame));
			}
		}
	}
}

void Gun::Render(sf::RenderWindow* window) {
	window->draw(*m_sprite);
}

sf::Vector2f Gun::GetPositon() {
	return m_sprite->getPosition();
}

int Gun::GetDame() {
	return m_dame;
}
