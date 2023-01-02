#include "SSDeath.h"

SSDeath::SSDeath(ICreep* creep) {
	m_creep = creep;
}

void SSDeath::Init() {
	m_animation = new Animation(*ASSET->getTexture("Creep/Skeleton/Skeleton_death"), sf::Vector2i(13, 1), 0.03f);
	m_animation->setScale(m_creep->GetScale());
}

void SSDeath::Update(float deltaTime) {
	m_animation->setScale(m_creep->GetScale().x * m_creep->GetFaceDir(), m_creep->GetScale().y);
	m_animation->setPosition(m_creep->GetHitBox()->getPosition());
	if (m_animation->Play(deltaTime)) {
		m_creep->SetDead(true);
	}
}

void SSDeath::Render(sf::RenderWindow* window) {
	window->draw(*m_animation);
}
