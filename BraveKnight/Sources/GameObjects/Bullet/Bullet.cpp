#include "Bullet.h"
#include "../Cursor/Cursor.h"
#include "../Gun/Gun.h"
#include "../Component/Collider/Collider.h"

Bullet::Bullet() {
}

Bullet::~Bullet() {
	delete m_collider;
	delete m_hitBox;
	delete m_animation;
}

Bullet::Bullet(sf::Vector2f startPosition, float angle, float radius, int dame) {
	m_startPosition = startPosition;
	m_angle = angle;
	m_dame = dame;
	m_scale = 1.3f * globalScale;
	m_hitBox = new HitBox(sf::Vector2i(16 * m_scale.x, 16 * m_scale.y));
	m_hitBox->setOrigin(m_hitBox->getSize().x / 2.f, m_hitBox->getSize().y / 2.f);
	m_hitBox->Init(sf::Vector2f(1000.f, 1000.f));
	m_hitBox->setPosition(sf::Vector2f(m_startPosition.x + radius * cos(m_angle * PI / 180), m_startPosition.y + radius * sin(m_angle * PI / 180)));
	m_collider = new Collider(m_hitBox);
	m_animation = new Animation(*ASSET->getTexture("Bullet/Bullet"), sf::Vector2i(5, 1), 0.1f);
	m_explode = new Animation(*ASSET->getTexture("Bullet/Explosion"), sf::Vector2i(8, 1), 0.05f);
	m_animation->setScale(m_scale);
	m_isExplode = false;
}

void Bullet::Init() {
}

void Bullet::Update(float deltaTime) {
	m_animation->setPosition(m_hitBox->getPosition());
	m_hitBox->move(m_hitBox->GetVelocity().x * cos(m_angle * PI / 180) * deltaTime, m_hitBox->GetVelocity().y * sin(m_angle * PI / 180) * deltaTime);
	if (!m_hitBox->IsAlive()) {
		if (m_animation != m_explode) m_animation = m_explode;
		if (m_animation->Play(deltaTime)) m_isExplode = true;
	}
	else m_animation->Update(deltaTime);
}

void Bullet::Render(sf::RenderWindow* window) {
	window->draw(*m_animation);
}

Collider* Bullet::GetCollider() {
	return m_collider;
}

HitBox* Bullet::GetHitBox() {
	return m_hitBox;
}

Animation* Bullet::GetAnimation() {
	return m_animation;
}

bool Bullet::IsExplode() {
	return m_isExplode;
}

int Bullet::GetDame() {
	return m_dame;
}
