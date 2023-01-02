#include "GSMenu.h"

GSMenu::GSMenu() {
}

GSMenu::~GSMenu() {
}

void GSMenu::Exit() {
}

void GSMenu::Pause() {
}

void GSMenu::Resume() {
}

void GSMenu::Init() {
	m_sprite.setTexture(*ASSET->getTexture("Background"));
	m_titleSprite.setTexture(*ASSET->getTexture("Title_game"));
	m_titleSprite.setColor(sf::Color(170, 125, 79));
	m_titleSprite.setOrigin((sf::Vector2f)m_titleSprite.getTexture()->getSize() / 2.f);
	m_titleSprite.setPosition(screenWidth / 2.f, screenHeight / 2.f - 200.f);
	GameButton* btn;

	// Play button
	btn = new GameButton();
	btn->Init("Play");
	btn->setSize(sf::Vector2f(200.f, 200.f));
	btn->setOrigin(btn->getSize() / 2.f);
	btn->setPosition(sf::Vector2f(screenWidth / 2.f, screenHeight / 2.f + 100.f));
	btn->setOnClick([]() {GSM->ChangeState(StateTypes::PLAY); });
	m_listBtn->push_back(btn);

	// High Score Button
	btn = new GameButton();
	btn->Init("High_score");
	btn->setSize(sf::Vector2f(100.f, 100.f));
	btn->setOrigin(btn->getSize() / 2.f);
	btn->setPosition(sf::Vector2f(screenWidth / 2.f - 200.f, screenHeight / 2.f + 300.f));
	btn->setOnClick([]() {GSM->ChangeState(StateTypes::HIGH_SCORE); });
	m_listBtn->push_back(btn);

	// Help button
	btn = new GameButton();
	btn->Init("Help");
	btn->setSize(sf::Vector2f(100.f, 100.f));
	btn->setOrigin(btn->getSize() / 2.f);
	btn->setPosition(sf::Vector2f(screenWidth / 2.f, screenHeight / 2.f + 300.f));
	btn->setOnClick([]() {GSM->ChangeState(StateTypes::HELP); });
	m_listBtn->push_back(btn);

	// Quit Button
	btn = new GameButton();
	btn->Init("Quit");
	btn->setSize(sf::Vector2f(100.f, 100.f));
	btn->setOrigin(btn->getSize() / 2.f);
	btn->setPosition(sf::Vector2f(screenWidth / 2.f + 200.f, screenHeight / 2.f + 300.f));
	btn->setOnClick([]() {WConnector->getWindow()->close(); });
	m_listBtn->push_back(btn);
}

void GSMenu::Update(float deltaTime) {
	for (GameButton* x : *m_listBtn) {
		x->Update(deltaTime);
	}
}

void GSMenu::Render(sf::RenderWindow* window) {
	window->draw(m_sprite);
	window->draw(m_titleSprite);
	for (GameButton* x : *m_listBtn) {
		x->Render(window);
	}
}