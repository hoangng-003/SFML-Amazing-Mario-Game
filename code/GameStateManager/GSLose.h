#pragma once

#include "GameStateBase.h"
class GSLose : public GameStateBase {
  public:
    GSLose();
    virtual ~GSLose();

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