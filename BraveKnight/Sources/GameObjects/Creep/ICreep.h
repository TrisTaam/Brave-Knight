#pragma once
#include "ICState.h"
#include "../Component/HitBox/HitBox.h"
#include "../StrongHold/StrongHold.h"
#include "../Turret/Turret.h"
#include "../Player/IPlayer.h"
#include "../Arrow/IArrow.h"

class ICreep {
public:
	ICreep();
	~ICreep();
	ICreep(sf::Vector2f position, sf::Vector2i HP);
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void ChangeNextState(ICState::STATE nextState) = 0;
	virtual ICState::STATE GetState() = 0;
	virtual sf::Vector2f GetScale() = 0;
	Collider* GetCollider();
	HitBox* GetHitBox();
	void SetFaceDir(int faceDir);
	int GetFaceDir();
	void Move(float deltaTime);
	int GetDame();
	sf::Vector2i GetHP();
	void TakeDame(int dame);
	void SetAttackAt(TAG tag);
	TAG GetAttackAt();
	void SetTurretToAttack(Turret* turret);
	Turret* GetTurretToAttack();
	void SetDead(bool isDead);
	bool IsDead();
protected:
	HitBox* m_hitBox;
	Collider* m_collider;
	int m_faceDir;
	int m_dame;
	sf::Vector2i m_HP;
	sf::Vector2f m_position;
	TAG m_attackAt;
	Turret* m_turretToAttack;
	sf::RectangleShape* m_healthBar;
	bool m_isDead;
};