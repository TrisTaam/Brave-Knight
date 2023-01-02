#include "ResourceManager.h"

ResourceManager::ResourceManager(){
    m_path = "assets/";
    m_texturePath = m_path + "Textures/";
    m_fontPath = m_path + "Fonts/";
    m_soundPath = m_path + "Sounds/";
}

ResourceManager::~ResourceManager(){
    for (auto x : m_mapTexture) {
        if (x.second != nullptr) {
            delete x.second;
        }
    }
    m_mapTexture.clear();
}

void ResourceManager::addTexture(string name){
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(m_texturePath + name + ".png");
    auto x = m_mapTexture.find(name);
    if (x != m_mapTexture.end()) {
        return;
    }
    m_mapTexture.insert(pair<string, sf::Texture*>(name, texture));
}

void ResourceManager::removeTexture(string name){
    auto x = m_mapTexture.find(name);
    if (x == m_mapTexture.end()) {
        return;
    }
    if (x->second != nullptr) {
        delete x->second;
    }
    m_mapTexture.erase(x);
}

sf::Texture* ResourceManager::getTexture(string name){
    auto x = m_mapTexture.find(name);
    if (x != m_mapTexture.end()) {
        return x->second;
    }
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(m_texturePath + name + ".png");
    m_mapTexture.insert(pair<string, sf::Texture*>(name, texture));
    return texture;
}

void ResourceManager::addFont(std::string name) {
    sf::Font* font = new sf::Font();
    font->loadFromFile(m_fontPath + name + ".ttf");
    auto x = m_mapFont.find(name);
    if (x != m_mapFont.end()) {
        return;
    }
    m_mapFont.insert(pair<string, sf::Font*>(name, font));
}

void ResourceManager::removeFont(std::string name) {
    auto x = m_mapFont.find(name);
    if (x == m_mapFont.end()) {
        return;
    }
    if (x->second != nullptr) {
        delete x->second;
    }
    m_mapFont.erase(x);
}

sf::Font* ResourceManager::getFont(std::string name) {
    auto x = m_mapFont.find(name);
    if (x != m_mapFont.end()) {
        return x->second;
    }
    sf::Font* font = new sf::Font();
    font->loadFromFile(m_fontPath + name + ".ttf");
    m_mapFont.insert(pair<string, sf::Font*>(name, font));
    return font;
}

void ResourceManager::addSound(std::string name) {
    sf::Sound* sound = new sf::Sound();
    sf::SoundBuffer* buffer = new sf::SoundBuffer();
    buffer->loadFromFile(m_soundPath + name + ".wav");
    sound->setBuffer(*buffer);
    m_mapSound.insert(pair<string, sf::Sound*>(name, sound));
}

void ResourceManager::removeSound(std::string name) {
    auto x = m_mapSound.find(name);
    if (x == m_mapSound.end()) {
        return;
    }
    if (x->second != nullptr) {
        delete x->second;
    }
    m_mapSound.erase(x);
}

sf::Sound* ResourceManager::getSound(std::string name) {
    auto x = m_mapSound.find(name);
    if (x != m_mapSound.end()) {
        return x->second;
    }
    sf::Sound* sound = new sf::Sound();
    sf::SoundBuffer* buffer = new sf::SoundBuffer();
    buffer->loadFromFile(m_soundPath + name + ".wav");
    sound->setBuffer(*buffer);
    m_mapSound.insert(pair<string, sf::Sound*>(name, sound));
    return sound;
}

void ResourceManager::addMusic(std::string name) {
    sf::Music* music = new sf::Music();
    music->openFromFile(m_soundPath + name + ".wav");
    auto x = m_mapMusic.find(name);
    if (x != m_mapMusic.end()) {
        return;
    }
    m_mapMusic.insert(pair<string, sf::Music*>(name, music));
}

void ResourceManager::removeMusic(std::string name) {
    auto x = m_mapMusic.find(name);
    if (x == m_mapMusic.end()) {
        return;
    }
    if (x->second != nullptr) {
        delete x->second;
    }
    m_mapMusic.erase(x);
}

sf::Music* ResourceManager::getMusic(std::string name) {
    sf::Music* music = new sf::Music();
    music->openFromFile(m_soundPath + name + ".wav");
    auto x = m_mapMusic.find(name);
    if (x != m_mapMusic.end()) {
        return x->second;
    }
    m_mapMusic.insert(pair<string, sf::Music*>(name, music));
    return music;
}
