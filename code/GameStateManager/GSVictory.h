#pragma once

#include "GameStateBase.h"
class GSVictory : public GameStateBase {
  public:
    GSVictory();
    virtual ~GSVictory();

    void Exit();
    void Pause();
    void Resume();

    void Init();
    void Update(float deltaTime);
    void Render(RenderWindow* window);

  private:
	list<GameButton*> m_ListBtn;
	Sprite _bg;
};