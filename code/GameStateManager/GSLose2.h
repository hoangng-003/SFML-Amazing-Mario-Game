#pragma once

#include "GameStateBase.h"
class GSLose2 : public GameStateBase {
  public:
    GSLose2();
    virtual ~GSLose2();

    void Exit();
    void Pause();
    void Resume();

    void Init();
    void Update(float deltaTime);
    void Render(RenderWindow* window);

  private:
	list<GameButton*> m_ListBtn;
	Sprite _bg[2];
};