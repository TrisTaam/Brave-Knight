#include "GameStateBase.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSPlay.h"
#include "GSPause.h"
#include "GSHelp.h"
#include "GSEnd.h"
#include "GSHighScore.h"

GameStateBase::GameStateBase() {
	m_listBtn = new std::list<GameButton*>;
}

GameStateBase::~GameStateBase() {}

GameStateBase* GameStateBase::CreateState(StateTypes st) {
	GameStateBase* gs = nullptr;
	switch (st) {
		case INVALID:
			break;
		case INTRO:
			gs = new GSIntro();
			break;
		case MENU:
			gs = new GSMenu();
			break;
		case PLAY:
			gs = new GSPlay();
			break;
		case HIGH_SCORE:
			gs = new GSHighScore();
			break;
		case HELP:
			gs = new GSHelp();
			break;
		case END:
			gs = new GSEnd();
			break;
		case PAUSE:
			gs = new GSPause();
			break;
		default:
			break;
	}
	return gs;
}