#include "Collider.h"

Collider::Collider() {
	m_hitBox = new HitBox();
}

Collider::Collider(HitBox* hitBox) {
	m_hitBox = hitBox;
}

Collider::~Collider() {
}

void Collider::Move(float x, float y) {
	m_hitBox->move(x, y);
}

bool Collider::CheckCollision(Collider* other) {
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();
	sf::Vector2f otherPosition = other->GetPosition();
	sf::Vector2f otherHalfSize = other->GetHalfSize();
	float deltaX = thisPosition.x - otherPosition.x;
	float deltaY = thisPosition.y - otherPosition.y;
	float intersectX = fabs(deltaX)-(thisHalfSize.x + otherHalfSize.x);
	float intersectY = fabs(deltaY)-(thisHalfSize.y + otherHalfSize.y);
	if (intersectX <= 0.f && intersectY <= 0.f) {
		if (intersectX > intersectY) {
			if (deltaX > 0.f) {
				Move(-intersectX, 0.f);
			}
			else {
				Move(intersectX, 0.f);
			}
		}
		else {
			if (deltaY > 0.f) {
				Move(0.f, -intersectY);
			}
			else {
				Move(0.f, intersectY);
			}
		}
		return true;
	}
	return false;
}

sf::Vector2f Collider::GetPosition() {
	return m_hitBox->getPosition();
}

sf::Vector2f Collider::GetHalfSize() {
	return m_hitBox->getSize() / 2.f;
}

HitBox* Collider::GetHitBox() {
	return m_hitBox;
}
