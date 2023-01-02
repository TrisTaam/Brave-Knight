#include "Tile.h"
#include "../../../GameManager/CollisionManager.h"

sf::Vector2f Tile::m_scale = 3.5f * globalScale;

Tile::Tile(int id, sf::Vector2i position) {
	m_sprite = new sf::Sprite();
	switch (id) {
		case 0:
			m_tileType = NONE;
			break;
		case 1:
			m_tileType = WALL_TOP_LEFT;
			break;
		case 2:
			m_tileType = WALL_TOP;
			break;
		case 3:
			m_tileType = WALL_TOP_RIGHT;
			break;
		case 4:
			m_tileType = WALL_LEFT;
			break;
		case 5:
			m_tileType = FLOOR;
			break;
		case 6:
			m_tileType = WALL_RIGHT;
			break;
		case 7:
			m_tileType = WALL_BOTTOM_LEFT;
			break;
		case 8:
			m_tileType = WALL_BOTTOM;
			break;
		case 9:
			m_tileType = WALL_BOTTOM_RIGHT;
			break;
		case 10:
			m_tileType = WALL_CORNER_LEFT;
			break;
		case 11:
			m_tileType = WALL_CORNER_RIGHT;
			break;
		default:
			break;
	}
	m_position = position;
}

void Tile::Init() {
	m_hitBox = new HitBox(sf::Vector2i(tileSize * m_scale.x, tileSize * m_scale.y));
	m_hitBox->setOrigin(m_hitBox->getSize() / 2.f);
	m_hitBox->setPosition(sf::Vector2f(m_position.y * tileSize * m_scale.y + tileSize * m_scale.y / 2, m_position.x * tileSize * m_scale.x + tileSize * m_scale.x / 2));
	switch (m_tileType) {
		case NONE:
			break;
		case WALL_TOP_LEFT:
			m_sprite->setTexture(*ASSET->getTexture("TileMap/Wall_top_left"));
			break;
		case WALL_TOP:
			m_sprite->setTexture(*ASSET->getTexture("TileMap/Wall_top"));
			break;
		case WALL_TOP_RIGHT:
			m_sprite->setTexture(*ASSET->getTexture("TileMap/Wall_top_right"));
			break;
		case WALL_LEFT:
			m_sprite->setTexture(*ASSET->getTexture("TileMap/Wall_left"));
			break;
		case FLOOR:
			m_sprite->setTexture(*ASSET->getTexture("TileMap/Floor"));
			break;
		case WALL_RIGHT:
			m_sprite->setTexture(*ASSET->getTexture("TileMap/Wall_right"));
			break;
		case WALL_BOTTOM_LEFT:
			m_sprite->setTexture(*ASSET->getTexture("TileMap/Wall_bottom_left"));
			break;
		case WALL_BOTTOM:
			m_sprite->setTexture(*ASSET->getTexture("TileMap/Wall_bottom"));
			break;
		case WALL_BOTTOM_RIGHT:
			m_sprite->setTexture(*ASSET->getTexture("TileMap/Wall_bottom_right"));
			break;
		case WALL_CORNER_LEFT:
			m_sprite->setTexture(*ASSET->getTexture("TileMap/Wall_corner_left"));
			break;
		case WALL_CORNER_RIGHT:
			m_sprite->setTexture(*ASSET->getTexture("TileMap/Wall_corner_right"));
			break;
		default:
			break;
	}
	m_sprite->setPosition(sf::Vector2f(m_position.y * tileSize * m_scale.y, m_position.x * tileSize * m_scale.x));
	m_sprite->setScale(m_scale);
	m_collider = new Collider(m_hitBox);
	if (m_tileType == FLOOR) {
		delete m_collider;
		delete m_hitBox;
	}
	if (m_tileType == NONE) {
		delete m_collider;
		delete m_hitBox;
	}
}

void Tile::Update(float deltaTime) {
}

void Tile::Render(sf::RenderWindow* window)  {
	window->draw(*m_sprite);
}

void Tile::SetTileType(TileType tileType) {
	m_tileType = tileType;
}

TileType Tile::GetTileType() {
	return m_tileType;
}

HitBox* Tile::GetHitBox() {
	return m_hitBox;
}

Collider* Tile::GetCollider() {
	return m_collider;
}
