#include "GameButton.h"

GameButton::GameButton() {
	m_isHandling = false;
	m_coolDown = 0.5f;
}

GameButton::~GameButton() {

}

void GameButton::Init(std:: string name) {
	this->setTexture(ASSET->getTexture("Button/" + name));
	this->setSize(sf::Vector2f(100, 100));
}

void GameButton::Update(float deltaTime) {
	m_coolDown -= deltaTime;
	if (WConnector->IsFocus()) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (m_coolDown <= 0.f) {
				HandleTouchEvent();
				m_coolDown = 0.5f;
			}
		}
	}
}

void GameButton::Render(sf::RenderWindow* window) {
	window->draw(*this);
}

void GameButton::HandleTouchEvent() {
	m_isHandling = false;
	if (this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnector->getWindow()))) {
		m_btnClickFunc();
		m_isHandling = true;
	}
}

bool GameButton::isHandling() {
	return m_isHandling;
}

void GameButton::setOnClick(void(*Func)()) {
	m_btnClickFunc = Func;
}