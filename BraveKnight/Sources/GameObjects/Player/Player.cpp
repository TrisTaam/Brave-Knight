#include "Player.h"
#include "PSIdle.h"
#include "PSRun.h"
#include "../../GameManager/CollisionManager.h"
#include "../Map/Map.h"
#include "../Turret/Turret.h"
#include "../UI/UI.h"

Player::Player() {
	m_nextState = IPState::STATE_NULL;
	m_idleState = new PSIdle(this);
	m_runState = new PSRun(this);
	m_currentState = m_idleState;
	m_scale = sf::Vector2f(3.f * globalScale.x, 3.f * globalScale.y);
	m_gun = new Gun();
	m_skill = new Skill();
	GConnector->SetGun(m_gun);
	m_faceDir = 1;
	m_HP = sf::Vector2i(1000, 1000);
	m_fury = sf::Vector2i(0, 200);
	m_coolDown = 0.5f;
	m_coin = 0;
	m_isUseSkill = false;
}

Player::~Player() {
	if (m_idleState != nullptr) delete m_idleState;
	if (m_runState != nullptr) delete m_runState;
	if (m_deathState != nullptr) delete m_deathState;
}

void Player::ChangeNextState(IPState::STATE nextState) {
	m_nextState = nextState;
}

void Player::Init() {
	m_hitBox = new HitBox(sf::Vector2i(12 * m_scale.x, 16 * m_scale.y));
	m_hitBox->setOrigin(m_hitBox->getSize().x / 2.f - 2 * m_scale.x * GetFaceDir(), m_hitBox->getSize().y / 2.f - 3 * m_scale.y);
	m_hitBox->Init(sf::Vector2f(300.f, 300.f));
	m_hitBox->setPosition(GConnector->GetMap()->GetMapSize().x / 2.f + 400, GConnector->GetMap()->GetMapSize().y / 2.f);
	m_hitBox->SetTag(PLAYER);
	m_collider = new Collider(m_hitBox);
	m_gun->Init();
	m_idleState->Init();
	m_runState->Init();
}

void Player::Update(float deltaTime) {
	m_currentTime += deltaTime;
	if (m_nextState != IPState::STATE_NULL) PerformStateChange();
	m_currentState->Update(deltaTime);
	float cursorX = GConnector->GetCursor()->GetPosition().x;
	if (cursorX <= m_hitBox->getPosition().x) m_faceDir = -1;
	else m_faceDir = 1;
	m_hitBox->setOrigin(m_hitBox->getSize().x / 2.f - 1 * GetScale().x * GetFaceDir(), m_hitBox->getSize().y / 2.f - 2 * GetScale().y);
	m_gun->Update(deltaTime);
	if (WConnector->IsFocus()) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			if (m_coin >= Turret::COST) {
				if (m_currentTime >= m_coolDown) {
					m_currentTime = 0.f;
					Turret* turret = new Turret(GConnector->GetCursor()->GetPosition());
					turret->Init();
					GConnector->GetListTurret()->push_back(turret);
					m_coin -= Turret::COST;
					Turret::COST += Turret::NUM_TURRET * 5;
				}
			}
			else {
				if (m_currentTime >= m_coolDown) {
					m_currentTime = 0.f;
					GeneralNotification* notification = new GeneralNotification("You don't have enough coin to build a turret", 1.f);
					notification->Init();
					GConnector->GetUI()->GetListNotification()->push_back(notification);
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (m_currentTime >= m_coolDown) {
				m_currentTime = 0.f;
				if (m_fury.x < m_fury.y) {
					GeneralNotification* notification = new GeneralNotification("You don't have enough fury to use skill", 1.f);
					notification->Init();
					GConnector->GetUI()->GetListNotification()->push_back(notification);
				}
				else {
					m_isUseSkill = true;
					m_fury.x = 0;
				}
			}
		}
	}
	if (m_isUseSkill) m_skill->Update(deltaTime);
}

void Player::Render(sf::RenderWindow* window) {
	m_currentState->Render(window);
	m_gun->Render(window);
}

HitBox* Player::GetHitBox() {
	return m_hitBox;
}

Collider* Player::GetCollider() {
	return m_collider;
}

sf::Vector2f Player::GetScale() {
	return m_scale;
}

void Player::Move(float moveX, float moveY) {
	m_hitBox->move(moveX, moveY);
}

void Player::SetFaceDir(int faceDir) {
	m_faceDir = faceDir;
}

int Player::GetFaceDir() {
	return m_faceDir;
}

sf::Vector2i Player::GetHP() {
	return m_HP;
}

void Player::SetFury(sf::Vector2i fury) {
	m_fury = fury;
}

sf::Vector2i Player::GetFury() {
	return m_fury;
}

void Player::TakeDame(int dame) {
	m_HP.x -= dame;
}

void Player::SetCoin(int coin) {
	m_coin = coin;
}

int Player::GetCoin() {
	return m_coin;
}

void Player::SetIsUseSkill(bool isUseSkill) {
	m_isUseSkill = isUseSkill;
}

void Player::PerformStateChange(){
	if (!m_nextState != IPState::STATE_NULL) 
		switch (m_nextState) {
			case IPState::STATE_IDLE:
				m_currentState = m_idleState;
				break;
			case IPState::STATE_RUN:
				m_currentState = m_runState;
				break;
			case IPState::STATE_DEATH:
				m_currentState = m_deathState;
				break;
			default:
				break;
		}
	m_nextState = IPState::STATE_NULL;
}
