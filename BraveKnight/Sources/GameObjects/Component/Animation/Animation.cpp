#include "Animation.h"

Animation::Animation() {
}

Animation::Animation(sf::Texture& texture, sf::Vector2i frameNum, float frameTime) {
    m_frameNum = frameNum;
    m_frameTime = frameTime;
    this->setTexture(texture);
    m_currentFrame = sf::Vector2i(0, 0);
    m_currentTime = 0.f;
    CalRectSize();
    CalRectPos();
    ApplyRect();
    this->setOrigin((sf::Vector2f)m_rectSize / 2.f);
}

void Animation::CalRectSize() {
    m_rectSize = sf::Vector2i(this->getTexture()->getSize().x / m_frameNum.x, this->getTexture()->getSize().y / m_frameNum.y);
}

void Animation::CalRectPos() {
    m_rectPos = sf::Vector2i(m_rectSize.x * m_currentFrame.x, m_rectSize.y * m_currentFrame.y);
}

void Animation::ApplyRect() {
    m_rect = sf::IntRect(m_rectPos, m_rectSize);
    this->setTextureRect(m_rect);
}

sf::Vector2i Animation::getRectSize() {
    return sf::Vector2i();
}

void Animation::Update(float deltaTime) {
    m_currentTime += deltaTime;
    if (m_currentTime >= m_frameTime) {
        m_currentFrame.x++;
        if (m_currentFrame.x == m_frameNum.x) {
            m_currentFrame.x = 0;
            m_currentFrame.y++;
            if (m_currentFrame.y == m_frameNum.y) m_currentFrame.y = 0;
        }
        CalRectPos();
        ApplyRect();
        m_currentTime -= m_frameTime;
    }
}

bool Animation::Play(float deltaTime) {
    m_currentTime += deltaTime;
    if (m_currentTime >= m_frameTime) {
        m_currentFrame.x++;
        if (m_currentFrame.x == m_frameNum.x) {
            m_currentFrame.x = 0;
            m_currentFrame.y++;
            if (m_currentFrame.y == m_frameNum.y) {
                m_currentFrame.y = 0;
                return true;
            }
        }
        CalRectPos();
        ApplyRect();
        m_currentTime -= m_frameTime;
    }
    return false;
}

void Animation::Reset(sf::Texture& texture, sf::Vector2i frameNum, float frameTime) {
    m_frameNum = frameNum;
    m_frameTime = frameTime;
    this->setTexture(texture);
    m_currentFrame = sf::Vector2i(0, 0);
    m_currentTime = 0.f;
    CalRectSize();
    CalRectPos();
    ApplyRect();
    this->setOrigin((sf::Vector2f)m_rectSize / 2.f);
}
