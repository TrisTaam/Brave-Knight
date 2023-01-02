#include "WaveNotification.h"

WaveNotification::WaveNotification() {
	m_wave = new Wave();
}

void WaveNotification::Init() {
	m_wave = GConnector->GetWave();
	setString("The creeps will spawn in " + to_string((int)m_wave->GetRemainTime()) + "s");
	setFont(*ASSET->getFont("m5x7"));
}

void WaveNotification::Update(float deltaTime) {
	if (m_wave->IsClear()) {
		setString("The creeps will spawn in " + to_string((int)m_wave->GetRemainTime()) + "s");
	}
	else {
		if (m_cnt) {
			setFillColor(sf::Color(getFillColor().r, getFillColor().g, getFillColor().b, getFillColor().a - 1));
			m_cnt--;
		}
		else m_isDone = true;
	}
}

void WaveNotification::Render(sf::RenderWindow* window) {
	if (m_cnt) window->draw(*this);
}
