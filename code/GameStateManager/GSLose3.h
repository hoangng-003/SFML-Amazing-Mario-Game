#pragma once

#include "GameStateBase.h"
class GSLose3 : public GameStateBase {
  public:
    GSLose3();
    virtual ~GSLose3();

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