#include "UI.h"
#include "../Player/IPlayer.h"
#include "../Wave/Wave.h"

UI::UI() {
	m_HPText = new sf::Text();
	m_playerHealthBar = new sf::RectangleShape();
	m_coinText = new sf::Text();
	m_numCoinText1 = new sf::Text();
	m_waveText = new sf::Text();
	m_needCoinText = new sf::Text();
	m_numCoinText2 = new sf::Text();
	m_listNotification = new std::list<INotification*>;
	m_fps = new sf::Text();
}

void UI::Init() {
	m_HPText->setString("HP");
	m_HPText->setFont(*ASSET->getFont("m5x7"));
	m_HPText->setCharacterSize(40);
	m_HPText->setFillColor(sf::Color::Red);
	m_HPText->setPosition(10.f, 0.f);

	m_playerHealthBar->setSize(sf::Vector2f(200.f, 20.f));
	m_playerHealthBar->setFillColor(sf::Color::Red);
	m_playerHealthBar->setPosition(m_HPText->getPosition().x + 30.f, m_HPText->getPosition().y + 20.f);

	m_coinText->setString("Coin: ");
	m_coinText->setFont(*ASSET->getFont("m5x7"));
	m_coinText->setPosition(m_HPText->getPosition().x, m_HPText->getPosition().y + 30.f);

	m_numCoinText1->setString(to_string(GConnector->GetPlayer()->GetCoin()));
	m_numCoinText1->setFont(*ASSET->getFont("m5x7"));
	m_numCoinText1->setFillColor(sf::Color::Yellow);
	m_numCoinText1->setPosition(m_coinText->getPosition().x + m_coinText->getLocalBounds().width, m_coinText->getPosition().y);

	m_animation1 = new Animation(*ASSET->getTexture("Coin/Coin"), sf::Vector2i(5, 1), 0.1f);
	m_animation1->setPosition(m_numCoinText1->getPosition().x + m_numCoinText1->getLocalBounds().width + 20.f, m_numCoinText1->getPosition().y + m_numCoinText1->getLocalBounds().height + 10.f);

	m_needCoinText->setString("Cost of a turret: ");
	m_needCoinText->setFont(*ASSET->getFont("m5x7"));
	m_needCoinText->setPosition(m_coinText->getPosition().x, m_coinText->getPosition().y + 20.f);

	m_numCoinText2->setString(to_string(Turret::COST));
	m_numCoinText2->setFont(*ASSET->getFont("m5x7"));
	m_numCoinText2->setFillColor(sf::Color::Yellow);
	m_numCoinText2->setPosition(m_needCoinText->getPosition().x + m_needCoinText->getLocalBounds().width, m_needCoinText->getPosition().y);

	m_animation2 = new Animation(*ASSET->getTexture("Coin/Coin"), sf::Vector2i(5, 1), 0.1f);
	m_animation2->setPosition(m_numCoinText2->getPosition().x + m_numCoinText2->getLocalBounds().width + 15.f, m_numCoinText2->getPosition().y + m_numCoinText2->getLocalBounds().height + 10.f);

	m_waveText->setString("WAVE " + to_string(Wave::NUM_WAVE));
	m_waveText->setFont(*ASSET->getFont("m5x7"));
	m_waveText->setCharacterSize(50);
	m_waveText->setOrigin(m_waveText->getLocalBounds().width / 2.f, m_waveText->getLocalBounds().height / 2.f);
	m_waveText->setPosition(screenWidth / 2.f, m_HPText->getPosition().y);

	m_fps->setFont(*ASSET->getFont("m5x7"));
	m_fps->setOrigin(m_fps->getLocalBounds().width / 2.f, m_fps->getLocalBounds().height / 2.f);
	m_fps->setPosition(screenWidth -175.f, m_HPText->getPosition().y + 20.f);
}

void UI::Update(float deltaTime) {
	sf::Vector2i playerHP = GConnector->GetPlayer()->GetHP();
	if (playerHP.x >= 0) {
		m_playerHealthBar->setSize(sf::Vector2f(200.f * playerHP.x / playerHP.y, 20.f));
	}
	else {
		m_playerHealthBar->setSize(sf::Vector2f(0.f, 20.f));
	}
	m_numCoinText1->setString(to_string(GConnector->GetPlayer()->GetCoin()));
	m_animation1->setPosition(m_numCoinText1->getPosition().x + m_numCoinText1->getLocalBounds().width + 15.f, m_numCoinText1->getPosition().y + m_numCoinText1->getLocalBounds().height + 10.f);
	m_numCoinText2->setString(to_string(Turret::COST));
	m_animation2->setPosition(m_numCoinText2->getPosition().x + m_numCoinText2->getLocalBounds().width + 15.f, m_numCoinText2->getPosition().y + m_numCoinText2->getLocalBounds().height + 10.f);
	m_waveText->setString("WAVE " + to_string(Wave::NUM_WAVE));
	m_fps->setString("FPS: " + to_string(int((float)1 / deltaTime)));
	float tmp = 0.f;
	for (INotification* x : *m_listNotification) {
		x->Update(deltaTime);
		x->setPosition(260.f, m_playerHealthBar->getPosition().y - m_playerHealthBar->getSize().y / 2.f + tmp);
		tmp += 20.f;
	}
	for (std::list<INotification*>::iterator it = m_listNotification->begin(); it != m_listNotification->end();) {
		if ((*it)->IsDone()) {
			INotification* turret = (*it);
			delete turret;
			it = m_listNotification->erase(it);
		}
		else {
			++it;
		}
	}
	m_animation1->Update(deltaTime);
	m_animation2->Update(deltaTime);
}

void UI::Render(sf::RenderWindow* window) {
	window->draw(*m_HPText);
	window->draw(*m_playerHealthBar);
	window->draw(*m_coinText);
	window->draw(*m_numCoinText1);
	window->draw(*m_animation1);
	window->draw(*m_needCoinText);
	window->draw(*m_numCoinText2);
	window->draw(*m_animation2);
	window->draw(*m_waveText);
	window->draw(*m_fps);
	for (INotification* x : *m_listNotification) {
		x->Render(window);
	}
}

std::list<INotification*>* UI::GetListNotification() {
	return m_listNotification;
}
