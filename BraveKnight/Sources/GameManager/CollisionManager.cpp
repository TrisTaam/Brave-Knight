#include "CollisionManager.h"
#include <list>

CollisionManager::CollisionManager() {
	m_player = GConnector->GetPlayer();
	m_listWall = GConnector->GetMap()->GetWall();
	m_strongHold = GConnector->GetStrongHold();
	m_listCreep = GConnector->GetWave()->GetListCreep();
	m_gun = GConnector->GetGun();
	m_listBullet = GConnector->GetListBullet();
	m_listTurret = GConnector->GetListTurret();
}

void CollisionManager::Init() {
	m_player = GConnector->GetPlayer();
	m_listWall = GConnector->GetMap()->GetWall();
	m_strongHold = GConnector->GetStrongHold();
	m_listCreep = GConnector->GetWave()->GetListCreep();
	m_gun = GConnector->GetGun();
	m_listBullet = GConnector->GetListBullet();
	m_listTurret = GConnector->GetListTurret();
}

void CollisionManager::PlayerAndWall() {
	for (Tile* x : *m_listWall) {
		if (m_player->GetCollider()->CheckCollision(x->GetCollider())) {
		}
	}
}

void CollisionManager::PlayerAndStrongHold() {
	if (m_player->GetCollider()->CheckCollision(m_strongHold->GetCollider())) {
	}
}

void CollisionManager::PlayerAndTurret() {
	for (Turret* x : *m_listTurret) {
		if (m_player->GetCollider()->CheckCollision(x->GetCollider())) {
		}
	}
}

void CollisionManager::PlayerAndCreep() {
	for (ICreep* x : *m_listCreep) {
		if (x->GetHitBox()->IsAlive()) {
			if (x->GetState() != ICState::STATE_DEATH) {
				if (x->GetAttackAt() == NOTHING && x->GetCollider()->CheckCollision(m_player->GetCollider())) {
					x->SetAttackAt(PLAYER);
					x->ChangeNextState(ICState::STATE_ATTACK);
				}
				else if (x->GetAttackAt() == TAG::PLAYER && !x->GetCollider()->CheckCollision(m_player->GetCollider())) {
					x->SetAttackAt(NOTHING);
					x->ChangeNextState(ICState::STATE_RUN);
				}
				else if (x->GetCollider()->CheckCollision(m_player->GetCollider())) {
				}
			}
		}
	}
}

void CollisionManager::BulletAndWall() {
	for (Bullet* x : *m_listBullet) {
		if (x->GetHitBox()->IsAlive()) {
			for (Tile* y : *m_listWall) {
				if (x->GetCollider()->CheckCollision(y->GetCollider())) {
					x->GetHitBox()->SetAlive(false);
					x->GetHitBox()->SetVelocity(sf::Vector2f(0.f, 0.f));
				}
			}
		}
	}
}

void CollisionManager::BulletAndStrongHold() {
	for (Bullet* x : *m_listBullet) {
		if (x->GetHitBox()->IsAlive()) {
			if (x->GetCollider()->CheckCollision(m_strongHold->GetCollider())) {
				x->GetHitBox()->SetAlive(false);
				x->GetHitBox()->SetVelocity(sf::Vector2f(0.f, 0.f));
			}
		}
	}
}

void CollisionManager::BulletAndTurret() {
	for (Bullet* x : *m_listBullet) {
		if (x->GetHitBox()->IsAlive()) {
			for (Turret* y : *m_listTurret) {
				if (x->GetCollider()->CheckCollision(y->GetCollider())) {
					x->GetHitBox()->SetAlive(false);
					x->GetHitBox()->SetVelocity(sf::Vector2f(0.f, 0.f));
				}
			}
		}
	}
}

void CollisionManager::BulletAndCreep() {
	for (Bullet* x : *m_listBullet) {
		if (x->GetHitBox()->IsAlive()) {
			for (ICreep* y : *m_listCreep) {
				if (y->GetHitBox()->IsAlive()) {
					if (x->GetCollider()->CheckCollision(y->GetCollider())) {
						x->GetHitBox()->SetAlive(false);
						x->GetHitBox()->SetVelocity(sf::Vector2f(0.f, 0.f));
						y->takeDame(x->GetDame());
						break;
					}
				}
			}
		}
	}
}

void CollisionManager::CreepAndWall() {
	for (ICreep* x : *m_listCreep) {
		if (x->GetHitBox()->IsAlive()) {
			for (Tile* y : *m_listWall) {
				if (y->GetHitBox()->IsAlive()) {
					if (x->GetCollider()->CheckCollision(y->GetCollider())) {

					}
				}
			}
		}
	}
}

void CollisionManager::CreepAndStrongHold() {
	bool flag = false;
	for (ICreep* x : *m_listCreep) {
		if (x->GetHitBox()->IsAlive()) {
			if (x->GetAttackAt() == NOTHING && x->GetCollider()->CheckCollision(m_strongHold->GetCollider())) {
				x->SetAttackAt(STRONG_HOLD);
				x->ChangeNextState(ICState::STATE_ATTACK);
				flag = true;
			}
			else if (x->GetAttackAt() == TAG::STRONG_HOLD && !x->GetCollider()->CheckCollision(m_strongHold->GetCollider())) {
				x->SetAttackAt(NOTHING);
				x->ChangeNextState(ICState::STATE_RUN);
			}
			else if (x->GetAttackAt() == TAG::STRONG_HOLD) {
				flag = true;
			}
		}
	}
	if (flag) GConnector->GetArrow()->ChangeNextState(IAState::STATE_ALERT);
	else GConnector->GetArrow()->ChangeNextState(IAState::STATE_NORMAL);
}

void CollisionManager::CreepAndTurret() {
	for (ICreep* x : *m_listCreep) {
		if (x->GetHitBox()->IsAlive()) {
			for (Turret* y : *m_listTurret) {
				if (y->GetHitBox()->IsAlive()) {
					if (x->GetAttackAt() == NOTHING && x->GetCollider()->CheckCollision(y->GetCollider())) {
						x->SetAttackAt(TURRET);
						x->ChangeNextState(ICState::STATE_ATTACK);
						x->SetTurretToAttack(y);
					}
					else if (x->GetAttackAt() == TAG::TURRET && x->GetTurretToAttack() == y && !x->GetCollider()->CheckCollision(y->GetCollider())) {
						x->SetAttackAt(NOTHING);
						x->ChangeNextState(ICState::STATE_RUN);
					}
				}
			}
		}
	}
}

void CollisionManager::Update() {
	PlayerAndWall();
	PlayerAndStrongHold();
	PlayerAndTurret();
	PlayerAndCreep();
	BulletAndWall();
	//BulletAndStrongHold();
	//BulletAndTurret();
	BulletAndCreep();
	CreepAndWall();
	CreepAndStrongHold();
	CreepAndTurret();
}
