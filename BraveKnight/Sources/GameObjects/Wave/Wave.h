#pragma once
#include "../Creep/ICreep.h"

class Wave {
public:
	static int NUM_WAVE;
	static sf::Vector2i SKELETON_HP;
	static sf::Vector2i DEMON_HP;
	Wave();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Spawn(float deltaTime);
	std::list<ICreep*>* GetListCreep();
	float GetRemainTime();
	bool IsClear();
private:
	std::list<ICreep*>* m_listCreep;
	std::list<ICreep*>* m_tmp;
	sf::Vector2f m_portTal[4];
	float m_coolDown;
	float m_waitTime;
	float m_currentTime;
	bool m_isClear;
	int m_creepPerPortal;
	int m_cnt;
};