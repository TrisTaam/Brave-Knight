#include "Arrow.h"
#include "../Player/IPlayer.h"
#include "../StrongHold/StrongHold.h"
#include "ASNormal.h"
#include "ASAlert.h"
#include <string>

Arrow::Arrow() {
	m_nextState = IAState::STATE_NULL;
	m_normalState = new ASNormal(this);
	m_alertState = new ASAlert(this);
	m_currentState = m_normalState;
	m_scale = sf::Vector2f(0.5f * globalScale.x, 0.5f * globalScale.y);
	m_radius = 100.f * m_scale.x;
}

Arrow::~Arrow() {
	if (m_normalState != nullptr) delete m_normalState;
	if (m_alertState != nullptr) delete m_alertState;
}

void Arrow::ChangeNextState(IAState::STATE nextState) {
	m_nextState = nextState;
}

void Arrow::Init() {
	m_normalState->Init();
	m_alertState->Init();
	m_hitBox = new HitBox(sf::Vector2i(32 * m_scale.x, 38 * m_scale.y));
	m_hitBox->setOrigin(m_hitBox->getSize().x / 2.f, m_hitBox->getSize().y / 2.f);
	m_hitBox->Init(sf::Vector2f(500.f, 500.f));
}

void Arrow::Update(float deltaTime) {
	sf::Vector2f playerPos = GConnector->GetPlayer()->GetHitBox()->getPosition();
	sf::Vector2f strongHoldPos = GConnector->GetStrongHold()->GetPosition();
	float X = strongHoldPos.x - playerPos.x;
	float Y = strongHoldPos.y - playerPos.y;
	float angle = GameMath::GetAngle(playerPos, strongHoldPos);
	if (m_nextState != IAState::STATE_NULL) PerformStateChange();
	m_currentState->Update(deltaTime, angle);
}

void Arrow::Render(sf::RenderWindow* window) {
	m_currentState->Render(window);
}

HitBox* Arrow::GetHitBox() {
	return m_hitBox;
}

sf::Vector2f Arrow::GetScale() {
	return m_scale;
}

sf::Vector2f Arrow::GetPosition() {
	return m_hitBox->getPosition();
}

float Arrow::GetRadius() {
	return m_radius;
}

void Arrow::PerformStateChange() {
	if (!m_nextState != IAState::STATE_NULL)
		switch (m_nextState) {
			case IAState::STATE_NORMAL:
				m_currentState = m_normalState;
				break;
			case IAState::STATE_ALERT:
				m_currentState = m_alertState;
				break;
			default:
				break;
		}
	m_nextState = IAState::STATE_NULL;
}
