#include "GSHighScore.h"

GSHighScore::GSHighScore() {
	m_sprite = new sf::Sprite();
	m_title = new sf::Text();
	m_text = new sf::Text;
}

GSHighScore::~GSHighScore() {
}

void GSHighScore::Exit() {
}

void GSHighScore::Pause() {
}

void GSHighScore::Resume() {
}

void GSHighScore::Init() {
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

	m_title->setString("HIGH SCORE");
	m_title->setFont(*ASSET->getFont("m5x7"));
	m_title->setCharacterSize(100);
	m_title->setOrigin(m_title->getLocalBounds().width / 2.f, m_title->getLocalBounds().height / 2.f);
	m_title->setPosition(m_sprite->getPosition().x, m_sprite->getPosition().y - m_sprite->getTexture()->getSize().y / 2.f + 100.f);

	sf::String s = "Rank";
	for (int i = 1; i <= 70; ++i) {
		s += ".";
	}
	s += "Wave\n";
	sf::String tmp;
	std::vector<int> vectorScore = GConnector->GetScore();
	for (int i = 0; i <vectorScore.size(); ++i) {
		tmp = to_string(i+1);
		if (tmp.getSize() == 1) tmp.insert(0, "0");
		for (int j = 1; j <= 80; ++j) tmp += ".";
		s += tmp;
		tmp = to_string(vectorScore[i]);
		if (tmp.getSize() == 1) tmp.insert(0, "0");
		s += (tmp + "\n");
	}
	m_text->setString(s);
	m_text->setFont(*ASSET->getFont("m5x7"));
	m_text->setCharacterSize(40);
	m_text->setFillColor(sf::Color::Blue);
	m_text->setPosition(m_sprite->getPosition().x - m_sprite->getTexture()->getSize().x / 2.f + 150.f, m_sprite->getPosition().y - m_sprite->getTexture()->getSize().y / 2.f + 250.f);
}

void GSHighScore::Update(float deltaTime) {
	for (GameButton* x : *m_listBtn) {
		x->Update(deltaTime);
	}
}

void GSHighScore::Render(sf::RenderWindow* window) {
	window->draw(*m_sprite);
	for (GameButton* x : *m_listBtn) {
		x->Render(window);
	}
	window->draw(*m_title);
	window->draw(*m_text);
}