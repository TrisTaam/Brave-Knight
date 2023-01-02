#pragma once
#include "SFML/Audio.hpp"
#include "Singleton.h"
#include "../GameObjects/Component/Animation/Animation.h"
#include "../GameObjects/Component/GameButton/GameButton.h"
#include "../GameObjects/Component/GameMath/GameMath.h"
#include "GameConnector.h"
#include <string>
#include <map>
using namespace std;

class CollisionManager;
class Collider;

#define ASSET ResourceManager::GetInstance()

class ResourceManager :public CSingleton<ResourceManager> {
public:
	ResourceManager();
	~ResourceManager();
	void addTexture(string name);
	void removeTexture(string name);
	sf::Texture* getTexture(string name);
	void addFont(std::string name);
	void removeFont(std::string name);
	sf::Font* getFont(std::string name);
	void addSound(std::string name);
	void removeSound(std::string name);
	sf::Sound* getSound(std::string name);
	void addMusic(std::string name);
	void removeMusic(std::string name);
	sf::Music* getMusic(std::string name);
private:
	map<string, sf::Texture*> m_mapTexture;
	map<string, sf::Font*> m_mapFont;
	map<string, sf::Sound*> m_mapSound;
	map<string, sf::Music*> m_mapMusic;
	string m_path;
	string m_texturePath;
	string m_fontPath;
	string m_soundPath;
};