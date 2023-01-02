#include "GSPause.h"
#include "GSPlay.h"

GSPause::GSPause() {
	m_sprite = new sf::Sprite();
	m_text = new sf::Text();
}

GSPause::~GSPause() {
}

void GSPause::Exit() {
}

void GSPause::Pause() {
}

void GSPause::Resume() {
}

void GSPause::Init() {
	WConnector->getWindow()->setMouseCursorVisible(true);
	m_sprite->setTexture(*ASSET->getTexture("Frame"));
	m_sprite->setOrigin((sf::Vector2f)m_sprite->getTexture()->getSize() / 2.f);
	m_sprite->setScale(0.6f, 0.3f);
	m_sprite->setPosition(screenWidth / 2.f, screenHeight / 2.f);

	m_text->setString("PAUSE");
	m_text->setFont(*ASSET->getFont("m5x7"));
	m_text->setCharacterSize(70);
	m_text->setOrigin(m_text->getLocalBounds().width / 2.f, m_text->getLocalBounds().height / 2.f);
	m_text->setPosition(m_sprite->getPosition().x, m_sprite->getPosition().y - m_sprite->getTexture()->getSize().y / 2.f + 295.f);
	GameButton* btn;

	// Restart button
	btn = new GameButton();
	btn->Init("Restart");
	btn->setSize(sf::Vector2f(100.f, 100.f));
	btn->setOrigin(btn->getSize() / 2.f);
	btn->setPosition(screenWidth / 2.f - 110.f, screenHeight / 2.f);
	btn->setOnClick([]() {
		GConnector->SetScore(Wave::NUM_WAVE);
		GSM->PopState();
		GSM->PopState();
		GSM->ChangeState(StateTypes::PLAY);
		}
	);
	m_listBtn->push_back(btn);

	// Resume button
	btn = new GameButton();
	btn->Init("Play");
	btn->setSize(sf::Vector2f(100.f, 100.f));
	btn->setOrigin(btn->getSize() / 2.f);
	btn->setPosition(screenWidth / 2.f, screenHeight / 2.f);
	btn->setOnClick([]() {
		GSM->PopState();
		}
	);
	m_listBtn->push_back(btn);

	// Home button
	btn = new GameButton();
	btn->Init("Home");
	btn->setSize(sf::Vector2f(100.f, 100.f));
	btn->setOrigin(btn->getSize() / 2.f);
	btn->setPosition(screenWidth / 2.f + 110.f, screenHeight / 2.f);
	btn->setOnClick([]() {
		GConnector->SetScore(Wave::NUM_WAVE);
		GSM->PopState();
		GSM->PopState();
		}
	);
	m_listBtn->push_back(btn);
}

void GSPause::Update(float deltaTime) {
	for (GameButton* x : *m_listBtn) {
		x->Update(deltaTime);
	}
}

void GSPause::Render(sf::RenderWindow* window) {
	window->setView(window->getDefaultView());
	window->draw(*m_sprite);
	window->draw(*m_text);
	for (GameButton* x : *m_listBtn) {
		x->Render(window);
	}
}