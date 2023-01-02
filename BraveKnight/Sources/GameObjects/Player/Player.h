#pragma once
#include "IPlayer.h"
#include "../Gun/Gun.h"

class Player :public IPlayer {
public:
	Player();
	~Player();
	void ChangeNextState(IPState::STATE nextState);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	HitBox* GetHitBox();
	Collider* GetCollider();
	sf::Vector2f GetScale();
	void Move(float moveX, float moveY);
	void SetFaceDir(int faceDir);
	int GetFaceDir();
	sf::Vector2i GetHP();
	void TakeDame(int dame);
	void SetCoin(int coin);
	int GetCoin();
private:
	void PerformStateChange();
	HitBox* m_hitBox;
	Collider* m_collider;
	IPState::STATE m_nextState;
	IPState* m_currentState;
	IPState* m_idleState;
	IPState* m_runState;
	IPState* m_deathState;
	sf::Vector2f m_scale;
	Gun* m_gun;
	int m_faceDir;
	sf::Vector2i m_HP;
	int m_coin;
	float m_speed;
	float m_coolDown;
	float m_currentTime;
};