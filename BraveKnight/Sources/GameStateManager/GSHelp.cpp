#include "GSHelp.h"

GSHelp::GSHelp() {
	m_sprite = new sf::Sprite();
	m_title = new sf::Text();
	m_text = new sf::Text;
}

GSHelp::~GSHelp() {
}

void GSHelp::Exit() {
}

void GSHelp::Pause() {
}

void GSHelp::Resume() {
}

void GSHelp::Init() {
	m_sprite->setTexture(*ASSET->getTexture("Frame"));
	m_sprite->setOrigin((sf::Vector2f)m_sprite->getTexture()->getSize() / 2.f);
	m_sprite->setScale(1.f, 0.8f);
	m_sprite->setPosition(screenWidth / 2.f, screenHeight / 2.f);
	GameButton* btn;

	// Close button
	btn = new GameButton();
	btn->Init("Close");
	btn->setSize(sf::Vector2f(100.f, 100.f));
	btn->setOrigin(btn->getSize() / 2.f);
	btn->setPosition(m_sprite->getPosition().x + m_sprite->getTexture()->getSize().x / 2.f - 40.f, m_sprite->getPosition().y - m_sprite->getTexture()->getSize().y / 2.f + 150.f);
	btn->setOnClick([]() {
		GSM->PopState();
		}
	);
	m_listBtn->push_back(btn);

	m_title->setString("HELP");
	m_title->setFont(*ASSET->getFont("m5x7"));
	m_title->setCharacterSize(100);
	m_title->setOrigin(m_title->getLocalBounds().width / 2.f, m_title->getLocalBounds().height / 2.f);
	m_title->setPosition(m_sprite->getPosition().x, m_sprite->getPosition().y - m_sprite->getTexture()->getSize().y / 2.f + 100.f);
	
	m_text->setString("Press W, A, S, D to move your player\nPress right to build a turret\nPress left click to shoot\nPress SPACE to use skill\nPress F to turn ON/OFF auto fire\nNote that: You will lose if your player die\nor your Strong Hold is destroyed");
	m_text->setFont(*ASSET->getFont("m5x7"));
	m_text->setCharacterSize(40);
	m_text->setFillColor(sf::Color::Blue);
	m_text->setPosition(m_sprite->getPosition().x - m_sprite->getTexture()->getSize().x / 2.f + 120.f, m_sprite->getPosition().y - m_sprite->getTexture()->getSize().y / 2.f + 250.f);
}

void GSHelp::Update(float deltaTime) {
	for (GameButton* x : *m_listBtn) {
		x->Update(deltaTime);
	}
}

void GSHelp::Render(sf::RenderWindow* window) {
	window->draw(*m_sprite);
	for (GameButton* x : *m_listBtn) {
		x->Render(window);
	}
	window->draw(*m_title);
	window->draw(*m_text);
}