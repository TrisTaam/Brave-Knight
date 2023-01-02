#include "SSAttack.h"

SSAttack::SSAttack(ICreep* creep) {
	m_creep = creep;
}

void SSAttack::Init() {
	m_animation = new Animation(*ASSET->getTexture("Creep/Skeleton/Skeleton_attack"), sf::Vector2i(13, 1), 0.08f);
	m_animation->setScale(m_creep->GetScale());
}

void SSAttack::Update(float deltaTime) {
	m_animation->setScale(m_creep->GetScale().x * m_creep->GetFaceDir(), m_creep->GetScale().y);
	m_creep->GetHitBox()->SetVelocity(sf::Vector2f(0.f, 0.f));
	m_animation->setPosition(m_creep->GetHitBox()->getPosition());
	if (m_animation->Play(deltaTime)) {
		if (m_creep->GetAttackAt() == STRONG_HOLD) {
			GConnector->GetStrongHold()->TakeDame(m_creep->GetDame());
		}
		else if (m_creep->GetAttackAt() == PLAYER) {
			GConnector->GetPlayer()->TakeDame(m_creep->GetDame());
		}
		else if (m_creep->GetAttackAt() == TURRET) {
			m_creep->GetTurretToAttack()->TakeDame(m_creep->GetDame());
			if (m_creep->GetTurretToAttack()->GetHP().x <= 0) {
				m_creep->SetAttackAt(NOTHING);
				m_creep->ChangeNextState(STATE_RUN);
			}
		}
	}
}

void SSAttack::Render(sf::RenderWindow* window) {
	window->draw(*m_animation);
}
