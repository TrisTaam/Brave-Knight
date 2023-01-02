#include "Skeleton.h"
#include "SSRun.h"
#include "SSAttack.h"
#include "SSDeath.h"
#include "../../../GameManager/CollisionManager.h"
#include "../../Map/Map.h"

Skeleton::Skeleton() :ICreep() {
}

Skeleton::Skeleton(sf::Vector2f position, sf::Vector2i HP) :ICreep(position, HP) {
	m_nextState = ICState::STATE_NULL;
	m_runState = new SSRun(this);
	m_attackState = new SSAttack(this);
	m_deathState = new SSDeath(this);
	m_currentState = m_runState;
	m_scale = sf::Vector2f(2.f * globalScale.x, 2.f * globalScale.y);
	m_faceDir = 1;
	m_dame = 50;
	SetAttackAt(NOTHING);
	m_healthBar = new sf::RectangleShape();
}

Skeleton::~Skeleton() {
	if (m_runState != nullptr) delete m_runState;
	if (m_attackState != nullptr) delete m_attackState;
	if (m_deathState != nullptr) delete m_deathState;
}

void Skeleton::ChangeNextState(ICState::STATE nextState) {
	m_nextState = nextState;
}

ICState::STATE Skeleton::GetState() {
	return m_nextState;
}

void Skeleton::Init() {
	m_hitBox = new HitBox(sf::Vector2i(23 * m_scale.x, 32 * m_scale.y));
	m_hitBox->setOrigin(m_hitBox->getSize() / 2.f);
	m_hitBox->Init(sf::Vector2f(150.f, 150.f));
	m_hitBox->setPosition(m_position);
	m_hitBox->SetTag(CREEP);
	m_collider = new Collider(m_hitBox);
	m_runState->Init();
	m_attackState->Init();
	m_deathState->Init();
	m_healthBar->setSize(sf::Vector2f(25.f, 5.f));
	m_healthBar->setFillColor(sf::Color::Red);
	m_healthBar->setOrigin(m_healthBar->getSize() / 2.f);
	m_healthBar->setPosition(m_hitBox->getPosition().x, m_hitBox->getPosition().y + 30.f);
}

void Skeleton::Update(float deltaTime) {
	m_healthBar->setPosition(m_hitBox->getPosition().x, m_hitBox->getPosition().y + 30.f);
	if (m_HP.x <= 0) {
		m_healthBar->setSize(sf::Vector2f(0.f, 5.f));
		m_hitBox->SetAlive(false);
		ChangeNextState(ICState::STATE_DEATH);
	}
	else {
		m_healthBar->setSize(sf::Vector2f(25.f * m_HP.x / m_HP.y, 5.f));
	}
	if (m_nextState != ICState::STATE_NULL) PerformStateChange();
	m_currentState->Update(deltaTime);
}

void Skeleton::Render(sf::RenderWindow* window) {
	m_currentState->Render(window);
	window->draw(*m_healthBar);
}

sf::Vector2f Skeleton::GetScale() {
	return m_scale;
}

void Skeleton::PerformStateChange() {
	if (!m_nextState != ICState::STATE_NULL)
		switch (m_nextState) {
		case ICState::STATE_RUN:
			m_currentState = m_runState;
			break;
		case ICState::STATE_ATTACK:
			m_currentState = m_attackState;
			break;
		case ICState::STATE_DEATH:
			m_currentState = m_deathState;
			break;
		default:
			break;
		}
	m_nextState = ICState::STATE_NULL;
}