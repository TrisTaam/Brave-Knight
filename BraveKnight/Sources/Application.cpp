#include "Application.h"
#include "GameStateManager/GameStateBase.h"

void Application::Run() {
	Init();
	sf::Clock clock;
	float deltaTime = 0.f;
	WConnector->SetFocus(true);
	while (m_window->isOpen()) {
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (m_window->pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				m_window->close();
			}
			if (event.type == sf::Event::GainedFocus) {
				WConnector->SetFocus(true);
			}
			if (event.type == sf::Event::LostFocus) {
				WConnector->SetFocus(false);
			}
		}
		Update(deltaTime);
		Render();
	}
}

Application::~Application() {
	if (m_window != nullptr) delete m_window;
}

void Application::Init() {
	m_window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), titleGame, sf::Style::Close);
	m_window->setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width - screenWidth) / 2, (sf::VideoMode::getDesktopMode().height - screenHeight - titleBarSize) / 2));
	m_window->setFramerateLimit(240);
	m_window->setVerticalSyncEnabled(false);
	m_icon.loadFromFile("assets/Textures/Icon.png");
	m_window->setIcon(512, 512, m_icon.getPixelsPtr());
	GSM->ChangeState(StateTypes::INTRO);
	WConnector->setWindow(m_window);
}

void Application::Update(float deltaTime) {
	if (GSM->NeedToChangeState()) {
		GSM->PerformStateChange();
	}
	GSM->CurrentState()->Update(deltaTime);
}

void Application::Render() {
	GSM->CurrentState()->Render(m_window);
	m_window->display();
}
