#pragma once

#include "GameManagers/ResourcesManager.h"
#include "GameConfig.h"
#include "GameStateManager/GameStateMachine.h"

using namespace sf;
using namespace std;

class Application{
  public:
    void Run();
    ~Application();
    void setSound(SoundBuffer* soundBuffer , bool isLoop);
  private:
    void Init();
    void Update(float deltaTime);
    void Render();    

    RenderWindow* _window;
    Sound _sound;
};