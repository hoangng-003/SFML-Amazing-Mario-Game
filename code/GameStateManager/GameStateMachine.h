#pragma once

#include "../GameManagers/Singleton.h"
#include <list>
using namespace std;

enum StateTypes{
  INVALID = 0,
  MENU,
  LOSE,
  MAP1,
  LOSE2,
  MAP2,
  LOSE3,
  MAP3,
  END,
};

class GameStateBase;

class GameStateMachine: public CSingleton<GameStateMachine>{
  public:
    GameStateMachine();
    ~GameStateMachine();

    void ChangeState(GameStateBase* state);
    void ChangeState(StateTypes st);
    void PushState(StateTypes st);
    void PopState();

    void PerformStateChange();

    GameStateBase* currentState() const;
    GameStateBase* nextState() const;
    bool isNeedToChangeState();
    bool isHasState();
  private:
    list <GameStateBase*> _StateStack;
    GameStateBase* _ActiveState;
    GameStateBase* _NextState;

};