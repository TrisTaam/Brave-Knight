#pragma once
#include "IPState.h"
#include "../Component/HitBox/HitBox.h"

class IPlayer {
public:
	virtual void ChangeNextState(IPState::STATE nextState) = 0;
	virtual HitBox* GetHitBox() = 0;
	virtual sf::Vector2f GetScale() = 0;
	virtual Collider* GetCollider() = 0;
	virtual void Move(float moveX, float moveY) = 0;
	virtual void SetFaceDir(int faceDir) = 0;
	virtual int GetFaceDir() = 0;
	virtual void TakeDame(int dame) = 0;
	virtual void SetCoin(int coin) = 0;
	virtual int GetCoin() = 0;
	virtual sf::Vector2i GetHP() = 0;
private:
};