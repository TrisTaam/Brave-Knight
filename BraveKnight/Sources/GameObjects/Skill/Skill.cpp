#include "Skill.h"
#include "../Bullet/Bullet.h"
#include "../Player/IPlayer.h"

Skill::Skill() {
	m_currentTime = 0.f;
	m_coolDown = 0.f;
	m_cnt = 0;
}

void Skill::Update(float deltaTime) {
	if (m_cnt >= 719) {
		GConnector->GetPlayer()->SetIsUseSkill(false);
		m_cnt = 0;
	}
	else {
		m_currentTime += deltaTime;
		if (m_currentTime >= m_coolDown) {
			sf::Vector2f position = GConnector->GetPlayer()->GetHitBox()->getPosition();
			m_currentTime = 0.f;
			GConnector->GetListBullet()->push_back(new Bullet(position, (float)m_cnt, 0.f, 40));
			m_cnt++;
		}
	}
}
