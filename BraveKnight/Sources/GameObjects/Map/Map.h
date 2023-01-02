#pragma once
#include "Tile/Tile.h"
#include <list>

class Map {
public:
	Map();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	sf::Vector2f GetMapSize();
	std::list<Tile*>* GetWall();
private:
	std::vector<std::vector<int>> m_mapID;
	std::vector<std::vector<Tile*>> m_tileMap;
	std::list<Tile*>* m_listWall;
};