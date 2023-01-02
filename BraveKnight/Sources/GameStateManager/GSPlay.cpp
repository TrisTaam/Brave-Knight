#include "GSPlay.h"
#include "../GameManager/CollisionManager.h"

GSPlay::GSPlay() {
	m_map = new Map();
	m_player = new Player();
	m_wave = new Wave();
	m_cursor = new Cursor();
	m_view = new sf::View();
	m_arrow = new Arrow();
	m_map = new Map();
	m_strongHold = new StrongHold();
	m_listBullet = new std::list<Bullet*>;
	m_listTurret = new std::list<Turret*>;
	m_UI = new UI();
	GConnector->SetPlayer(m_player);
	GConnector->SetCursor(m_cursor);
	GConnector->SetMap(m_map);
	GConnector->SetStrongHold(m_strongHold);
	GConnector->SetWave(m_wave);
	GConnector->SetListBullet(m_listBullet);
	GConnector->SetListTurret(m_listTurret);
	GConnector->SetArrow(m_arrow);
	GConnector->SetUI(m_UI);
	Wave::NUM_WAVE = 0;
	Wave::SKELETON_HP = sf::Vector2i(400, 400);
	Wave::DEMON_HP = sf::Vector2i(200, 200);
	Turret::COST = 50;
	Turret::NUM_TURRET = 0;
	m_coolDown = 0.5f;
}

GSPlay::~GSPlay() {
	delete this;
}

void GSPlay::Exit() {
}

void GSPlay::Pause() {
}

void GSPlay::Resume() {
}

void GSPlay::Init() {
	GameButton* btn;
	// Button pause
	btn = new GameButton();
	btn->Init("Pause");
	btn->setSize(sf::Vector2f(50.f, 50.f));
	btn->setOrigin(btn->getSize() / 2.f);
	btn->setPosition(screenWidth - 50.0f, 40.0f);
	btn->setOnClick([]() {
		GSM->ChangeState(StateTypes::PAUSE);
		}
	);
	m_listBtn->push_back(btn);
	m_map->Init();
	m_player->Init();
	m_wave->Init();
	m_cursor->Init();
	m_arrow->Init();
	m_view->setSize(screenWidth, screenHeight);
	m_strongHold->Init();
	m_UI->Init();
	ColliManager->Init();
}

void GSPlay::Update(float deltaTime) {
	m_coolDown -= deltaTime;
	if (WConnector->IsFocus()) {
		if (m_player->GetHP().x <= 0 || m_strongHold->GetHp().x <= 0) {
			GConnector->SetScore(Wave::NUM_WAVE);
			GSM->ChangeState(StateTypes::END);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			if (m_coolDown <= 0.f) {
				GSM->ChangeState(StateTypes::PAUSE);
				m_coolDown = 0.5f;
			}
		}
		m_map->Update(deltaTime);
		m_player->Update(deltaTime);
		m_cursor->Update(deltaTime);
		m_arrow->Update(deltaTime);
		m_view->setCenter(m_player->GetHitBox()->getPosition());
		m_strongHold->Update(deltaTime);
		m_wave->Update(deltaTime);
		for (Bullet* x : *m_listBullet) {
			x->Update(deltaTime);
		}
		for (std::list<Bullet*>::iterator it = m_listBullet->begin(); it != m_listBullet->end();) {
			if ((*it)->IsExplode()) {
				Bullet* bullet = (*it);
				delete bullet;
				it = m_listBullet->erase(it);
			}
			else {
				++it;
			}
		}
		for (Turret* x : *m_listTurret) {
			x->Update(deltaTime);
		}
		for (std::list<Turret*>::iterator it = m_listTurret->begin(); it != m_listTurret->end();) {
			if ((*it)->IsExplode()) {
				Turret* turret = (*it);
				delete turret;
				it = m_listTurret->erase(it);
			}
			else {
				++it;
			}
		}
		m_UI->Update(deltaTime);
		ColliManager->Update();
		for (GameButton* x : *m_listBtn) {
			x->Update(deltaTime);
		}
	}
	else {
		GSM->ChangeState(StateTypes::PAUSE);
	}
}

void GSPlay::Render(sf::RenderWindow* window) {
	window->clear(sf::Color(37, 19, 26));
	window->setView(*m_view);
	m_map->Render(window);
	m_arrow->Render(window);
	m_player->Render(window);
	m_strongHold->Render(window);
	for (Bullet* x : *m_listBullet) {
		x->Render(window);
	}
	m_wave->Render(window);
	m_cursor->Render(window);
	for (Turret* x : *m_listTurret) {
		x->Render(window);
	}
	window->setView(window->getDefaultView());
	m_UI->Render(window);
	for (GameButton* x : *m_listBtn) {
		x->Render(window);
	}
	window->setView(*m_view);
}