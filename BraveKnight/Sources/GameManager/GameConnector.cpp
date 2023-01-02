#include "GameConnector.h"
#include <fstream>

GameConnector::GameConnector() {
	m_player = nullptr;
}

void GameConnector::SetPlayer(IPlayer* player) {
	m_player = player;
}

IPlayer* GameConnector::GetPlayer () {
	return m_player;
}

void GameConnector::SetCursor(Cursor* cursor) {
	m_cursor = cursor;
}

Cursor* GameConnector::GetCursor() {
	return m_cursor;
}

void GameConnector::SetMap(Map* map) {
	m_map = map;
}

Map* GameConnector::GetMap() {
	return m_map;
}

void GameConnector::SetStrongHold(StrongHold* strongHold) {
	m_strongHold = strongHold;
}

StrongHold* GameConnector::GetStrongHold() {
	return m_strongHold;
}

void GameConnector::SetGun(Gun* gun) {
	m_gun = gun;
}

Gun* GameConnector::GetGun() {
	return m_gun;
}

void GameConnector::SetWave(Wave* wave) {
	m_wave = wave;
}

Wave* GameConnector::GetWave() {
	return m_wave;
}

void GameConnector::SetListBullet(std::list<Bullet*>* listBullet) {
	m_listBullet = listBullet;
}

std::list<Bullet*>* GameConnector::GetListBullet() {
	return m_listBullet;
}

void GameConnector::SetListTurret(std::list<Turret*>* listTurret) {
	m_listTurret = listTurret;
}

std::list<Turret*>* GameConnector::GetListTurret() {
	return m_listTurret;
}

void GameConnector::SetArrow(IArrow* arrow) {
	m_arrow = arrow;
}

IArrow* GameConnector::GetArrow() {
	return m_arrow;
}

void GameConnector::SetUI(UI* ui) {
	m_UI = ui;
}

UI* GameConnector::GetUI() {
	return m_UI;
}

void GameConnector::SetScore(int score) {
	std::fstream file;
	std::vector<int> vectorScore;
	int x;
	file.open("assets/HighScore.txt");
	while (file >> x) {
		vectorScore.push_back(x);
	}
	file.close();
	vectorScore.push_back(score);
	sort(vectorScore.begin(), vectorScore.end(), std::greater<int>());
	while (vectorScore.size() > 10) {
		vectorScore.pop_back();
	}
	file.open("assets/HighScore.txt");
	for (int x : vectorScore) {
		file << x << "\n";
	}
	file.close();
}

std::vector<int> GameConnector::GetScore() {
	std::fstream file;
	std::vector<int> vectorScore;
	int x;
	file.open("assets/HighScore.txt");
	while (file >> x) {
		vectorScore.push_back(x);
	}
	file.close();
	return vectorScore;
}
