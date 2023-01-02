#include "WindowConnector.h"

WindowConnector::WindowConnector() {
	m_window = nullptr;
}

void WindowConnector::setWindow(sf::RenderWindow* window) {
	m_window = window;
}

sf::RenderWindow* WindowConnector::getWindow() {
	return m_window;
}

void WindowConnector::SetFocus(bool focus) {
	m_isFocus = focus;
}

bool WindowConnector::IsFocus() {
	return m_isFocus;
}
