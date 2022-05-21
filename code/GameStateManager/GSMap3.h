#pragma once

#include "GameStateBase.h"
#include "../GameObjects/Animation/Animation.h"

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

    void setSprite(Texture* texture, float posx , float posy , int i);


  private:
      Animation* _mario;
      Sprite _sprite[2];
      RectangleShape _checkPoint[2];
};