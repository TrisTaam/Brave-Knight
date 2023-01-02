#pragma once
#include "SFML/Graphics.hpp"
#include "Singleton.h"
#include "../GameConfig.h"
#include <list>

class IPlayer;
class Cursor;
class Map;
class StrongHold;
class Gun;
class ICreep;
class Wave;
class Turret;
class Bullet;
class IArrow;
class UI;

#define GConnector GameConnector::GetInstance()

class GameConnector :public CSingleton<GameConnector> {
public:
	GameConnector();
	void SetPlayer(IPlayer* player);
	IPlayer* GetPlayer();
	void SetCursor(Cursor* cursor);
	Cursor* GetCursor();
	void SetMap(Map* map);
	Map* GetMap();
	void SetStrongHold(StrongHold* strongHold);
	StrongHold* GetStrongHold();
	void SetGun(Gun* gun);
	Gun* GetGun();
	void SetWave(Wave* wave);
	Wave* GetWave();
	void SetListBullet(std::list<Bullet*>* listBullet);
	std::list<Bullet*>* GetListBullet();
	void SetListTurret(std::list<Turret*>* listTurret);
	std::list<Turret*>* GetListTurret();
	void SetArrow(IArrow* arrow);
	IArrow* GetArrow();
	void SetUI(UI* ui);
	UI* GetUI();
	void SetScore(int score);
	std::vector<int> GetScore();
private:
	IPlayer* m_player;
	Cursor* m_cursor;
	Map* m_map;
	StrongHold* m_strongHold;
	Gun* m_gun;
	Wave* m_wave;
	std::list<Bullet*>* m_listBullet;
	std::list<Turret*>* m_listTurret;
	IArrow* m_arrow;
	UI* m_UI;
};