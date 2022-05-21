#include "Application.h"
#include "GameStateManager/GameStateBase.h"

  void Application ::  Run(){

    Init();
    Clock clock;
    float deltaTime = 0.f;

    while (_window->isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        Event event;
        while (_window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                _window->close();
        }
        Update(deltaTime);
        Render();
    }
  }

  Application:: ~Application(){
    if(_window != nullptr) delete _window;
  }

  void Application ::  Init(){

    _window = new RenderWindow(VideoMode(WIDTH, HEIGHT), TITLE);
    _window->setFramerateLimit(60);
    _window->setVerticalSyncEnabled(false);
    WConnect->setWindow(_window);
    setSound(DATA->getSoundBuffer("rickroll"), true);

    GSM->ChangeState(StateTypes::MENU);
  }

  void Application ::  Update(float deltaTime){
    if(GSM->isNeedToChangeState()){
      GameStateMachine :: GetInstance()->PerformStateChange();
    }
    GameStateMachine:: GetInstance()->currentState()->Update(deltaTime);
    
  }

  void Application :: Render(){
    _window->clear( Color :: White );

    GameStateMachine :: GetInstance()->currentState()->Render(_window);

    _window->display();

  }

  void Application :: setSound(SoundBuffer* soundBuffer , bool isLoop){
    _sound.setBuffer(*soundBuffer);
    _sound.play();
    _sound.setLoop(isLoop);
  }



