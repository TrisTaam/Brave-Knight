#pragma once
#include "../GameManager/Singleton.h"
#include <list>
class GameStateBase;
using namespace std;

#define GSM GameStateMachine::GetInstance()

enum StateTypes {
	INVALID = 0,
	INTRO,
	MENU,
	PLAY,
	HIGH_SCORE,
	HELP,
	PAUSE,
	END,
};

class GameStateMachine :public CSingleton<GameStateMachine>{
public:
	GameStateMachine();
	~GameStateMachine();
	void ChangeState(GameStateBase* state);
	void ChangeState(StateTypes st);
	void PushState(StateTypes st);
	void PopState();
	void PerformStateChange();
	GameStateBase* CurrentState() const;
	GameStateBase* NextState() const;
	bool NeedToChangeState();
	bool HasState();
private:
	list<GameStateBase*> m_stateStack;
	GameStateBase* m_activeState;
	GameStateBase* m_nextState;
	bool m_isRunning;
};
