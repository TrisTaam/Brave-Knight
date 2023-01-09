#include "Demon.h"
#include "DSRun.h"
#include "DSAttack.h"
#include "DSDeath.h"
#include "../../../GameManager/CollisionManager.h"
#include "../../Map/Map.h"

Demon::Demon() :ICreep(){
}

Demon::Demon(sf::Vector2f position, sf::Vector2i HP) :ICreep(position, HP) {
	m_nextState = ICState::STATE_NULL;
	m_runState = new DSRun(this);
	m_attackState = new DSAttack(this);
	m_deathState = new DSDeath(this);
	m_currentState = m_runState;
	m_scale = sf::Vector2f(2.f * globalScale.x, 2.f * globalScale.y);
	m_faceDir = 1;
	m_dame = 30;
	SetAttackAt(NOTHING);
	m_healthBar = new sf::RectangleShape();
}

Demon::~Demon() {
	if (m_runState != nullptr) delete m_runState;
	if (m_attackState != nullptr) delete m_attackState;
	if (m_deathState != nullptr) delete m_deathState;
}

void Demon::ChangeNextState(ICState::STATE nextState) {
	if (m_nextState != nextState) m_nextState = nextState;
}

ICState::STATE Demon::GetState() {
	return m_nextState;
}

void Demon::Init() {
	printf("%d %d\n", m_HP.x, m_HP.y);
	m_hitBox = new HitBox(sf::Vector2i(40 * m_scale.x, 22 * m_scale.y));
	m_hitBox->setOrigin(m_hitBox->getSize() / 2.f);
	m_hitBox->Init(sf::Vector2f(200.f, 200.f));
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

void Demon::Update(float deltaTime) {
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

void Demon::Render(sf::RenderWindow* window) {
	m_currentState->Render(window);
	window->draw(*m_healthBar);
}

sf::Vector2f Demon::GetScale() {
	return m_scale;
}

void Demon::PerformStateChange() {
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