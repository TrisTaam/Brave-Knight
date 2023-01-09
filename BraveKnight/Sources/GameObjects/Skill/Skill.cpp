#include "Skill.h"
#include "../Bullet/Bullet.h"
#include "../Player/IPlayer.h"

Skill::Skill() {
}

void Skill::Do() {
	sf::Vector2f position = GConnector->GetPlayer()->GetHitBox()->getPosition();
	for (int i = 0; i <= 359; ++i) {
		GConnector->GetListBullet()->push_back(new Bullet(position, (float)i, 0.f, 40));
	}
}