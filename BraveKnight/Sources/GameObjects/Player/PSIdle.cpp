#include "PSIdle.h"
#include "../Cursor/Cursor.h"

PSIdle::PSIdle(IPlayer* player) {
	m_player = player;
}

void PSIdle::Init() {
	m_animation = new Animation(*ASSET->getTexture("Player/Player_idle"), sf::Vector2i(4, 1), 0.1f);
	m_animation->setScale(m_player->GetScale());
}

void PSIdle::Update(float deltaTime) {
	m_animation->Update(deltaTime);
	if (WConnector->IsFocus()) {
		m_animation->setScale(fabs(m_animation->getScale().x) * m_player->GetFaceDir(), m_animation->getScale().y);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) m_player->ChangeNextState(STATE_RUN);
		m_animation->setPosition(m_player->GetHitBox()->getPosition());
	}
}

void PSIdle::Render(sf::RenderWindow* window) {
	window->draw(*m_animation);
}
