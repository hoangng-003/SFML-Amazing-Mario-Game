#pragma once

#include "GameStateBase.h"
class GSMap2 : public GameStateBase {
  public:
    GSMap2();
    virtual ~GSMap2();

    void Exit();
    void Pause();
    void Resume();

    void Init();
    void Update(float deltaTime);
    void Render(RenderWindow* window);

    void setSprite(Texture* texture, float posx , float posy , int i);

  private:
    Sprite _sprite[12];
};