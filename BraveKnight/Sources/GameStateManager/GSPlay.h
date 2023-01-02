#pragma once
#include "GameStateBase.h"
#include "../GameObjects/Player/Player.h"
#include "../GameObjects/Cursor/Cursor.h"
#include "../GameObjects/Map/Map.h"
#include "../GameObjects/Arrow/Arrow.h"
#include "../GameObjects/Stronghold/Stronghold.h"
#include "../GameObjects/Wave/Wave.h"
#include "../GameObjects/Turret/Turret.h"
#include "../GameObjects/UI/UI.h"

class GSPlay :public GameStateBase {
public:
	GSPlay();
	~GSPlay();
	void Exit();
	void Pause();
	void Resume();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	Player* m_player;
	Cursor* m_cursor;
	Map* m_map;
	sf::View *m_view;
	Arrow* m_arrow;
	StrongHold* m_strongHold;
	Wave* m_wave;
	std::list<Bullet*>* m_listBullet;
	std::list<Turret*>* m_listTurret;
	UI* m_UI;
	float m_coolDown;
};