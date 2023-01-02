#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class Animation :public sf::Sprite {
public:
	Animation();
	Animation(sf::Texture& texture, sf::Vector2i frameNum, float frameTime);
	void CalRectSize();
	void CalRectPos();
	void ApplyRect();
	sf::Vector2i getRectSize();
	void Update(float deltaTime);
	bool Play(float deltaTime);
	void Reset(sf::Texture& texture, sf::Vector2i frameNum, float frameTime);
private:
	sf::Vector2i m_frameNum;
	sf::Vector2i m_currentFrame;
	sf::Vector2i m_rectPos;
	sf::Vector2i m_rectSize;
	sf::IntRect m_rect;
	float m_frameTime;
	float m_currentTime;
};