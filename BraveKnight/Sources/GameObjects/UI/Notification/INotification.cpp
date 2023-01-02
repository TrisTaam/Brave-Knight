#include "INotification.h"

INotification::INotification() {
	m_cnt = 255;
	m_isDone = false;
	m_coolDown = 0.0002f;
	m_currentTime = 0.f;
}

bool INotification::IsDone() {
	return m_isDone;
}
