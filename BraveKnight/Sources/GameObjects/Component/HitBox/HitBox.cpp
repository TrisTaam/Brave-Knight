#include "HitBox.h"

HitBox::HitBox() {
}

HitBox::HitBox(sf::Vector2i size) :RectangleShape((sf::Vector2f)size) {
	this->setOrigin((sf::Vector2f)size / 2.f);
	this->setFillColor(sf::Color(0, 0, 0, 0));
	this->setOutlineThickness(1.f);
	this->setOutlineColor(sf::Color::Red);
	m_velocity = sf::Vector2f(0.f, 0.f);
	m_isAlive = true;
}

HitBox::~HitBox() {
}

void HitBox::Init(sf::Vector2f velocity) {
	m_velocity = velocity;
}

void HitBox::SetVelocity(sf::Vector2f velocity) {
	m_velocity = velocity;
}

sf::Vector2f HitBox::GetVelocity() {
	return m_velocity;
}

void HitBox::SetAlive(bool alive) {
	m_isAlive = alive;
}

bool HitBox::IsAlive() {
	return m_isAlive;
}

void HitBox::SetTag(TAG tag) {
	m_tag = tag;
}

TAG HitBox::GetTag() {
	return m_tag;
}

