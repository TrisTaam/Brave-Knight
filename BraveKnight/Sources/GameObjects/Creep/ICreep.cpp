#include "ICreep.h"
#include "../Player/IPlayer.h"
#include "../StrongHold/StrongHold.h"

ICreep::ICreep() {
}

ICreep::~ICreep() {
	delete m_collider;
	delete m_hitBox;
	delete m_healthBar;
}

ICreep::ICreep(sf::Vector2f position, sf::Vector2i HP) {
	m_position = position;
	m_HP = HP;
}

Collider* ICreep::GetCollider() {
	return m_collider;
}

void ICreep::SetFaceDir(int faceDir) {
	m_faceDir = 1;
}

int ICreep::GetFaceDir() {
	return m_faceDir;
}

void ICreep::Move(float deltaTime) {
	sf::Vector2f creepPosition = m_hitBox->getPosition();
	sf::Vector2f playerPosition = GConnector->GetPlayer()->GetHitBox()->getPosition();
	sf::Vector2f strongHoldPosition = GConnector->GetStrongHold()->GetPosition();
	float angle;
	if (GameMath::GetDistance(creepPosition, playerPosition) < GameMath::GetDistance(creepPosition, strongHoldPosition)) {
		angle = GameMath::GetAngle(creepPosition, playerPosition);
		if (creepPosition.x <= playerPosition.x) m_faceDir = 1;
		else m_faceDir = -1;
	}
	else {
		angle = GameMath::GetAngle(creepPosition, strongHoldPosition);
		if (creepPosition.x <= strongHoldPosition.x) m_faceDir = 1;
		else m_faceDir = -1;
	}
	m_hitBox->move(m_hitBox->GetVelocity().x * cos(angle * PI / 180) * deltaTime, m_hitBox->GetVelocity().y * sin(angle * PI / 180) * deltaTime);
}

int ICreep::GetDame() {
	return m_dame;
}

sf::Vector2i ICreep::GetHP() {
	return m_HP;
}

void ICreep::TakeDame(int dame) {
	m_HP.x -= dame;
}

void ICreep::SetAttackAt(TAG tag) {
	m_attackAt = tag;
}

TAG ICreep::GetAttackAt() {
	return m_attackAt;
}

void ICreep::SetTurretToAttack(Turret* turret) {
	m_turretToAttack = turret;
}

Turret* ICreep::GetTurretToAttack() {
	return m_turretToAttack;
}

void ICreep::SetDead(bool isDead) {
	m_isDead = isDead;
}

bool ICreep::IsDead() {
	return m_isDead;
}

HitBox* ICreep::GetHitBox() {
	return m_hitBox;
}
