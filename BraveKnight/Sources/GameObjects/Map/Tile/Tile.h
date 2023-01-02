#pragma once
#include "../../../GameManager/ResourceManager.h"
#include "../../Component/HitBox/HitBox.h"

enum TileType {
	NONE,
	WALL_TOP_LEFT,
	WALL_TOP,
	WALL_TOP_RIGHT,
	WALL_LEFT,
	FLOOR,
	WALL_RIGHT,
	WALL_BOTTOM_LEFT,
	WALL_BOTTOM,
	WALL_BOTTOM_RIGHT,
	WALL_CORNER_LEFT,
	WALL_CORNER_RIGHT,
};

class Tile {
public:
	static sf::Vector2f m_scale;
	Tile(int id, sf::Vector2i position);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void SetTileType(TileType tileType);
	TileType GetTileType();
	HitBox* GetHitBox();
	Collider* GetCollider();
private:
	TileType m_tileType;
	sf::Sprite* m_sprite;
	sf::Vector2i m_position;
	HitBox* m_hitBox;
	Collider* m_collider;
};