#include "DSRun.h"

DSRun::DSRun(ICreep* creep) {
	m_creep = creep;
}

void DSRun::Init() {
	m_animation = new Animation(*ASSET->getTexture("Creep/Demon/Demon_run"), sf::Vector2i(8, 1), 0.1f);
	m_animation->setScale(m_creep->GetScale());
}

void DSRun::Update(float deltaTime) {
	m_animation->setScale(m_creep->GetScale().x * m_creep->GetFaceDir(), m_creep->GetScale().y);
	m_creep->GetHitBox()->SetVelocity(sf::Vector2f(200.f, 200.f));
	m_animation->setPosition(m_creep->GetHitBox()->getPosition().x - 3 * m_creep->GetScale().x, m_creep->GetHitBox()->getPosition().y);
	m_creep->Move(deltaTime);
	m_animation->Update(deltaTime);
}

void DSRun::Render(sf::RenderWindow* window) {
	window->draw(*m_animation);
}
