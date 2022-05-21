#include "GameStateMachine.h"
#include "GameStateBase.h"
    
    GameStateMachine:: GameStateMachine(){
        _ActiveState = nullptr;
        _NextState = nullptr;
    }
    GameStateMachine:: ~GameStateMachine(){
      while(!_StateStack.empty()){
        delete _StateStack.back();
      }
    }

    void GameStateMachine:: ChangeState(GameStateBase* state){
        _NextState = state;

    }
    void GameStateMachine::  ChangeState(StateTypes st){
      GameStateBase* gs = GameStateBase:: createState(st);
      ChangeState(gs);
    }
    void GameStateMachine::  PushState(StateTypes st){
      GameStateBase* gs = GameStateBase:: createState(st);
      if(!_StateStack.empty()){
        _StateStack.back()->Pause();
      }
      _NextState = gs;
    }
    void GameStateMachine::  PopState(){
      if(!_StateStack.empty()){
        _StateStack.back()->Exit();
        _StateStack.pop_back();
      }
      if(!_StateStack.empty()){
        _StateStack.back()->Resume();
      }
    }

    void GameStateMachine::  PerformStateChange(){
      if(_NextState != nullptr){
        if(!_StateStack.empty()){
          _StateStack.back()->Exit();
        }
        _StateStack.push_back(_NextState);
        _StateStack.back()->Init();
        _ActiveState = _NextState;
      }
      _NextState = nullptr;
    }

    GameStateBase* GameStateMachine :: currentState() const{
      return _ActiveState;
    }
    GameStateBase* GameStateMachine :: nextState() const{
      return _NextState;
    }
    bool GameStateMachine::  isNeedToChangeState(){
      return _NextState != nullptr;
    }
    bool GameStateMachine::  isHasState(){
      return _StateStack.size() > 0;
    }