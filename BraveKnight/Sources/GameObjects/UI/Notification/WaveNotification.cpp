#include "WaveNotification.h"

WaveNotification::WaveNotification() {
}

WaveNotification::WaveNotification(float coolDown) {
	m_wave = new Wave();
	m_coolDown = coolDown;
	m_currentTime = 0.f;
}

void WaveNotification::Init() {
	m_wave = GConnector->GetWave();
	setString("The creeps will spawn in " + to_string((int)m_wave->GetRemainTime()) + "s");
	setFont(*ASSET->getFont("m5x7"));
}

void WaveNotification::Update(float deltaTime) {
	m_currentTime += deltaTime;
	if (m_wave->IsClear()) {
		setString("The creeps will spawn in " + to_string((int)m_wave->GetRemainTime()) + "s");
	}
	else {
		if (m_currentTime >= deltaTime / 255.f) {
			m_currentTime = 0.f;
			if (m_cnt) {
				setFillColor(sf::Color(getFillColor().r, getFillColor().g, getFillColor().b, getFillColor().a - 1));
				m_cnt--;
			}
			else m_isDone = true;
		}
	}
}

void WaveNotification::Render(sf::RenderWindow* window) {
	if (m_cnt) window->draw(*this);
}
