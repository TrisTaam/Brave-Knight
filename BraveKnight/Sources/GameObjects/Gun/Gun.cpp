#include "Gun.h"
#include <cmath>
#include "../Cursor/Cursor.h"
#include "../UI/UI.h"

Gun::Gun() {
	m_scale = sf::Vector2f(2.f * globalScale.x, 2.f * globalScale.y);
	m_sprite = new sf::Sprite();
	m_coolDown1 = 0.5f;
	m_currentTime1 = 0.f;
	m_coolDown2 = 0.1f;
	m_currentTime2 = 0.f;
	m_dame = 50;
	m_autoFire = false;
}

void Gun::Init() {
	m_sprite->setTexture(*ASSET->getTexture("Gun/Gun"));
	m_sprite->setScale(m_scale);
}

void Gun::Update(float deltaTime) {
	m_currentTime1 += deltaTime;
	m_currentTime2 += deltaTime;
	if (WConnector->IsFocus()) {
		sf::Vector2f cursorPos = GConnector->GetCursor()->GetPosition();
		sf::Vector2f handPos = sf::Vector2f(GConnector->GetPlayer()->GetHitBox()->getPosition().x + 10 * GConnector->GetPlayer()->GetFaceDir(), GConnector->GetPlayer()->GetHitBox()->getPosition().y + 15);
		m_sprite->setPosition(handPos);
		m_sprite->setOrigin(10, 5);
		m_sprite->setScale(m_scale.x, fabs(m_scale.y) * GConnector->GetPlayer()->GetFaceDir());
		float angle = GameMath::GetAngle(handPos, cursorPos);
		m_sprite->setRotation(angle);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
			if (m_currentTime1 >= m_coolDown1) {
				m_currentTime1 = 0;
				m_autoFire = !m_autoFire;
				GeneralNotification* notification = new GeneralNotification("Auto Fire: " + (string)(m_autoFire?"ON":"OFF"), 1.f);
				notification->Init();
				GConnector->GetUI()->GetListNotification()->push_back(notification);
			}
		}
		if (m_autoFire || sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (m_currentTime2 >= m_coolDown2) {
				m_currentTime2 = 0;
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
