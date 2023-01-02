#include "../../GameManager/ResourceManager.h"
#include "Notification/INotification.h"
#include "Notification/WaveNotification.h"
#include "Notification/TurretNotification.h"

class UI {
public:
	UI();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	std::list<INotification*>* GetListNotification();
private:
	sf::Text* m_HPText;
	sf::RectangleShape* m_playerHealthBar;
	sf::Text* m_coinText;
	sf::Text* m_numCoinText1;
	Animation* m_animation1;
	sf::Text* m_waveText;
	sf::Text* m_needCoinText;
	sf::Text* m_numCoinText2;
	Animation* m_animation2;
	std::list<INotification*>* m_listNotification;
	sf::Text* m_fps;
};