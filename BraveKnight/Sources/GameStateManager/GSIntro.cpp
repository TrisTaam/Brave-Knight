#include "GSIntro.h"

GSIntro::GSIntro() {
	m_currentTime = 0.f;
	m_coolDown = 0.007f;
	m_cnt = 255;
}

GSIntro::~GSIntro() {
}

void GSIntro::Exit() {
}

void GSIntro::Pause() {
}

void GSIntro::Resume() {
}

void GSIntro::Init() {
	m_sprite.setTexture(*ASSET->getTexture("logo"));
	m_sprite.setScale(0.2f, 0.2f);
	m_sprite.setPosition(sf::Vector2f(screenWidth / 2.f, screenHeight / 2.f));
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getTextureRect().width / 2.f, m_sprite.getTextureRect().height / 2.f));
}

void GSIntro::Update(float deltaTime) {
	m_currentTime += deltaTime;
	if (m_cnt) {
		if (m_currentTime >= m_coolDown) {
			m_currentTime = 0.f;
			m_sprite.setColor(sf::Color(m_sprite.getColor().r, m_sprite.getColor().g, m_sprite.getColor().b, m_sprite.getColor().a - 1));
			m_cnt--;
		}
	}
	else GSM->ChangeState(StateTypes::MENU);
}

void GSIntro::Render(sf::RenderWindow* window) {
	window->clear(sf::Color(37, 19, 26));
	window->draw(m_sprite);
}