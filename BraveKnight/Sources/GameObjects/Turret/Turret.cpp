#include "Turret.h"
#include "../Map/Map.h"
#include "../../GameManager/CollisionManager.h"

int Turret::COST = 50;
int Turret::NUM_TURRET = 0;

Turret::Turret() {
}

Turret::~Turret() {
}

Turret::Turret(sf::Vector2f position) {
	Turret::NUM_TURRET++;
	m_sprite = new sf::Sprite();
	m_scale = sf::Vector2f(0.7f * globalScale.x, 0.7f * globalScale.y);
	m_position = position;
	m_radius = 500.f;
	m_circle = new sf::CircleShape(m_radius);
	m_coolDown = 0.1f;
	m_curentTime = 0.f;
	m_HP = sf::Vector2i(1000, 1000);
	m_dame = 40;
	m_isExplode = false;
	m_healthBar = new sf::RectangleShape();
}

void Turret::Init() {
	m_sprite->setTexture(*ASSET->getTexture("Turret/Turret"));
	m_sprite->setScale(m_scale);
	m_hitBox = new HitBox(sf::Vector2i((m_sprite->getTexture()->getSize().x - 80.f) * m_scale.x, (m_sprite->getTexture()->getSize().y - 50.f) * m_scale.y));
	m_hitBox->setOrigin(m_hitBox->getSize() / 2.f);
	m_hitBox->setPosition(m_position);
	m_hitBox->SetTag(TURRET);
	m_collider = new Collider(m_hitBox);
	m_sprite->setOrigin(m_hitBox->getSize().x / 2.f + 27.f / m_scale.x, m_hitBox->getSize().y / 2.f + 27.f / m_scale.y);
	m_sprite->setPosition(m_position);
	m_circle->setOrigin(m_radius, m_radius);
	m_circle->setFillColor(sf::Color(0, 0, 0, 0));
	m_circle->setOutlineColor(sf::Color(255, 0, 0, 100));
	m_circle->setOutlineThickness(1.f);
	m_circle->setPosition(m_position);
	m_animation = new Animation(*ASSET->getTexture("Turret/Exploding"), sf::Vector2i(12, 1), 0.1f);
	m_animation->setPosition(m_position);
	m_animation->setScale(sf::Vector2f(1.f, 1.f));
	m_healthBar->setSize(sf::Vector2f(50.f, 5.f));
	m_healthBar->setFillColor(sf::Color::Red);
	m_healthBar->setPosition(m_position.x - 25.f, m_position.y + 50.f);
}

void Turret::Update(float deltaTime) {
	m_curentTime += deltaTime;
	if (m_HP.x <= 0) {
		m_healthBar->setSize(sf::Vector2f(0.f * m_HP.x / m_HP.y, 5.f));
		m_hitBox->SetAlive(false);
	}
	else {
		m_healthBar->setSize(sf::Vector2f(50.f * m_HP.x / m_HP.y, 5.f));
	}
	if (m_hitBox->IsAlive()) {
		float distance = 1e9;
		float tmp;
		sf::Vector2f creepPosition;
		std::list<ICreep*>* listCreep = GConnector->GetWave()->GetListCreep();
		for (ICreep* x : *listCreep) {
			tmp = GameMath::GetDistance(m_position, x->GetHitBox()->getPosition());
			if (distance > tmp) {
				distance = tmp;
				creepPosition = x->GetHitBox()->getPosition();
			}
		}
		sf::Vector2f playerPosition = GConnector->GetPlayer()->GetHitBox()->getPosition();
		if (distance <= m_radius) {
			float angle = GameMath::GetAngle(m_position, creepPosition);
			m_sprite->setRotation(angle);
			if (m_curentTime >= m_coolDown) {
				m_curentTime = 0;
				GConnector->GetListBullet()->push_back(new Bullet(m_position, angle, 100.f * m_scale.x, m_dame));
			}
		}
	}
	else {
		if (m_animation->Play(deltaTime)) {
			m_isExplode = true;
		}
	}
}

void Turret::Render(sf::RenderWindow* window) {
	if (m_hitBox->IsAlive()) {
		window->draw(*m_sprite);
		window->draw(*m_circle);
		window->draw(*m_healthBar);
	}
	else {
		window->draw(*m_animation);
	}
}

HitBox* Turret::GetHitBox() {
	return m_hitBox;
}

sf::Vector2f Turret::GetPosition() {
	return m_sprite->getPosition();
}

Collider* Turret::GetCollider() {
	return m_collider;
}

int Turret::GetDame() {
	return m_dame;
}

void Turret::TakeDame(int dame) {
	m_HP.x -= dame;
}

bool Turret::IsExplode() {
	return m_isExplode;
}

sf::Vector2i Turret::GetHP() {
	return m_HP;
}

sf::Vector2f Turret::GetScale() {
	return m_scale;
}
