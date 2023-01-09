#include "Wave.h"
#include "../Creep/Skeleton/Skeleton.h"
#include "../Creep/Demon/Demon.h"
#include "../UI/UI.h"

int Wave::NUM_WAVE = 0;
sf::Vector2i Wave::SKELETON_HP = sf::Vector2i(400, 400);
sf::Vector2i Wave::DEMON_HP = sf::Vector2i(200, 200);

Wave::Wave() {
	m_listCreep = new std::list<ICreep*>;
	m_tmp = new std::list<ICreep*>;
	m_portTal[0] = sf::Vector2f(140.f, 2100.f);
	m_portTal[1] = sf::Vector2f(2100.f, 140.f);
	m_portTal[2] = sf::Vector2f(4060.f, 2100.f);
	m_portTal[3] = sf::Vector2f(2100.f, 4060.f);
	m_coolDown = 10.f;
	m_currentTime = 0.f;
	m_waitTime = 1.1f;
	m_creepPerPortal = 0;
	m_isClear = false;
	m_cnt = 0;
}

void Wave::Init(){
	for (int i = 1; i <= m_creepPerPortal * 2; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (i & 1) {
				m_tmp->push_back(new Skeleton(m_portTal[j], SKELETON_HP));
			}
			else {
				m_tmp->push_back(new Demon(m_portTal[j], DEMON_HP));
			}
		}
	}
}

void Wave::Update(float deltaTime) {
	m_currentTime += deltaTime;
	if (m_isClear) {
		if (m_currentTime >= m_coolDown) {
			NUM_WAVE++;
			m_cnt = 0;
			m_currentTime = 0.f;
			m_isClear = false;
			m_creepPerPortal++;
			m_isClear = false;
			if (NUM_WAVE >= 3 && NUM_WAVE < 10) {
				SKELETON_HP.x += 10;
				SKELETON_HP.y += 10;
				DEMON_HP.x += 10;
				DEMON_HP.y += 10;
			}
			else if (NUM_WAVE >= 10) {
				SKELETON_HP.x += 20 * (NUM_WAVE - 10);
				SKELETON_HP.y += 20 * (NUM_WAVE - 10);
				DEMON_HP.x += 20 * (NUM_WAVE - 10);
				DEMON_HP.y += 20 * (NUM_WAVE - 10);
			}
			Init();
			if (m_waitTime > 0.1f) m_waitTime -= 0.1f;
		}
	}
	else {
		sf::Vector2i fury = GConnector->GetPlayer()->GetFury();
		if (!m_tmp->empty()) {
			if (m_currentTime >= m_waitTime) {
				m_currentTime = 0;
				m_tmp->back()->Init();
				m_listCreep->push_back(m_tmp->back());
				m_tmp->pop_back();
			}
		}
		for (ICreep* x : *m_listCreep) {
			x->Update(deltaTime);
		}
		for (std::list<ICreep*>::iterator it = m_listCreep->begin(); it != m_listCreep->end();) {
			if ((*it)->IsDead()) {
				ICreep* creep = (*it);
				delete creep;
				it = m_listCreep->erase(it);
				m_cnt++;
				GConnector->GetPlayer()->SetCoin(GConnector->GetPlayer()->GetCoin() + 1);
				if (fury.x < fury.y) {
					GConnector->GetPlayer()->SetFury(sf::Vector2i(fury.x + 1, fury.y));
				}
			}
			else {
				++it;
			}
		}
		if (m_cnt == m_creepPerPortal * 8) {
			m_isClear = true;
			m_currentTime = 0;
			WaveNotification* notification = new WaveNotification(1.f);
			notification->Init();
			GConnector->GetUI()->GetListNotification()->push_back(notification);
		}
	}
}

void Wave::Render(sf::RenderWindow* window) {
	for (ICreep* x : *m_listCreep) {
		x->Render(window);
	}
}

void Wave::Spawn(float deltaTime) {
}

std::list<ICreep*>* Wave::GetListCreep() {
	return m_listCreep;
}

float Wave::GetRemainTime() {
	return m_coolDown - m_currentTime;
}

bool Wave::IsClear() {
	return m_isClear;
}
