#pragma once
#include "../GameObjects/Component/Collider/Collider.h"
#include "../GameObjects/Player/IPlayer.h"
#include "../GameObjects/Map/Map.h"
#include "../GameObjects/StrongHold/StrongHold.h"
#include "../GameObjects/Gun/Gun.h"
#include "../GameObjects/Wave/Wave.h"
#include "../GameObjects/Turret/Turret.h"
#include "GameConnector.h"

#define ColliManager CollisionManager::GetInstance()

class CollisionManager :public CSingleton<CollisionManager> {
public:
	CollisionManager();
	void Init();
	void PlayerAndWall();
	void PlayerAndStrongHold();
	void PlayerAndTurret();
	void PlayerAndCreep();
	void BulletAndWall();
	void BulletAndStrongHold();
	void BulletAndTurret();
	void BulletAndCreep();
	void CreepAndWall();
	void CreepAndStrongHold();
	void CreepAndTurret();
	void Update();
private:
	IPlayer* m_player;
	std::list<Tile*>* m_listWall;
	StrongHold* m_strongHold;
	std::list<ICreep*>* m_listCreep;
	Gun* m_gun;
	std::list<Bullet*>* m_listBullet;
	std::list<Turret*>* m_listTurret;
};