#pragma once

#include "../GameManagers/ResourcesManager.h"
#include "GameStateMachine.h"

using namespace sf;
using namespace std;

class GameStateBase {
  public: 
    GameStateBase();
    virtual ~GameStateBase();

    virtual void Exit() = 0;
    virtual void Pause() = 0;
    virtual void Resume() = 0;

    virtual void Init() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render(RenderWindow* window) = 0;

    static GameStateBase* createState(StateTypes st);
};