#pragma once
#include "SFML/Graphics.hpp"
#include "Singleton.h"

#define WConnector WindowConnector::GetInstance()

class WindowConnector :public CSingleton<WindowConnector> {
public:
	WindowConnector();
	void setWindow(sf::RenderWindow* window);
	sf::RenderWindow* getWindow();
	void SetFocus(bool focus);
	bool IsFocus();
private:
	sf::RenderWindow* m_window;
	bool m_isFocus;
};