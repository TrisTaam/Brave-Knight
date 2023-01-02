#include "SSRun.h"

SSRun::SSRun(ICreep* creep) {
	m_creep = creep;
}

void SSRun::Init() {
	m_animation = new Animation(*ASSET->getTexture("Creep/Skeleton/Skeleton_run"), sf::Vector2i(12, 1), 0.1f);
	m_animation->setScale(m_creep->GetScale());
}

void SSRun::Update(float deltaTime) {
	m_animation->setScale(m_creep->GetScale().x * m_creep->GetFaceDir(), m_creep->GetScale().y);
	m_creep->GetHitBox()->SetVelocity(sf::Vector2f(150.f, 150.f));
	m_animation->setPosition(m_creep->GetHitBox()->getPosition());
	m_creep->Move(deltaTime);
	m_animation->Update(deltaTime);
}

void SSRun::Render(sf::RenderWindow* window) {
	window->draw(*m_animation);
}
