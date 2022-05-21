#pragma once

#include "GameStateBase.h"
class GSMap3 : public GameStateBase {
  public:
    GSMap3();
    virtual ~GSMap3();

    void Exit();
    void Pause();
    void Resume();

    void Init();
    void Update(float deltaTime);
    void Render(RenderWindow* window);

  private:
    RectangleShape shape;
};