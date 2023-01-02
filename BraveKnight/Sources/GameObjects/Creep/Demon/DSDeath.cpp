#include "DSDeath.h"

DSDeath::DSDeath(ICreep* creep) {
	m_creep = creep;
}

void DSDeath::Init() {
	m_animation = new Animation(*ASSET->getTexture("Creep/Demon/Demon_death"), sf::Vector2i(4, 1), 0.1f);
	m_animation->setScale(m_creep->GetScale());
}

void DSDeath::Update(float deltaTime) {
	m_animation->setScale(m_creep->GetScale().x * m_creep->GetFaceDir(), m_creep->GetScale().y);
	m_animation->setPosition(m_creep->GetHitBox()->getPosition());
	if (m_animation->Play(deltaTime)) {
		m_creep->SetDead(true);
	}
}

void DSDeath::Render(sf::RenderWindow* window) {
	window->draw(*m_animation);
}
