#include "PSRun.h"
#include <math.h>

PSRun::PSRun(IPlayer* player) {
	m_player = player;
}

void PSRun::Init() {
	m_animation = new Animation(*ASSET->getTexture("Player/Player_run"), sf::Vector2i(4, 1), 0.1f);
	m_animation->setScale(m_player->GetScale());
}

void PSRun::Update(float deltaTime) {
	if (WConnector->IsFocus()) {
		m_animation->setScale(fabs(m_animation->getScale().x) * m_player->GetFaceDir(), m_animation->getScale().y);
		sf::Vector2f velocity = m_player->GetHitBox()->GetVelocity();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				m_player->Move(-velocity.x * deltaTime / sqrt(2), -velocity.y * deltaTime / sqrt(2));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				m_player->Move(velocity.x * deltaTime / sqrt(2), -velocity.y * deltaTime / sqrt(2));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				m_player->Move(-velocity.x * deltaTime / sqrt(2), velocity.y * deltaTime / sqrt(2));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				m_player->Move(velocity.x * deltaTime / sqrt(2), velocity.y * deltaTime / sqrt(2));
			}
			else {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					m_player->Move(-velocity.x * deltaTime, 0.f);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					m_player->Move(velocity.x * deltaTime, 0.f);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					m_player->Move(0.f, -velocity.y * deltaTime);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					m_player->Move(0.f, velocity.y * deltaTime);
				}
			}
			m_animation->Update(deltaTime);
			m_animation->setPosition(m_player->GetHitBox()->getPosition());
		}
		else m_player->ChangeNextState(STATE::STATE_IDLE);
	}
	else m_player->ChangeNextState(STATE::STATE_IDLE);
}

void PSRun::Render(sf::RenderWindow* window) {
	window->draw(*m_animation);
}
