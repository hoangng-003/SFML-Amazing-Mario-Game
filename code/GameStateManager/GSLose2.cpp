#include "GSLose2.h"
    
  GSLose2 ::  GSLose2(){

  }
    GSLose2 :: ~GSLose2(){

    }

    void GSLose2 ::   Exit(){

    }
    void GSLose2 ::   Pause(){

    }
    void GSLose2 ::   Resume(){

    }

    void GSLose2 ::   Init(){

      GameButton* button;

	    //Continue
	    button = new GameButton();
	    button->Init("continue");
	    button->setOnClick([]() {GSM->ChangeState(StateTypes::MAP2); });
	    button->setPosition(375, 265);
	    button->setSize(sf::Vector2f(150,50));
	    button->setOrigin(button->getSize() / 2.f);
	    m_ListBtn.push_back(button);

      //Play Again
	    button = new GameButton();
	    button->Init("playagain");
	    button->setOnClick([]() {GSM->ChangeState(StateTypes::MENU); });
	    button->setPosition(375 , 340);
	    button->setSize(sf::Vector2f(150,50));
	    button->setOrigin(button->getSize() / 2.f);
	    m_ListBtn.push_back(button);

      _bg[0].setTexture(*DATA->getTexture("losebg"));
	    _bg[0].setScale(1.4f,1.4f);
      
      _bg[1].setTexture(*DATA->getTexture("lose"));
	    _bg[1].setScale(0.5f,0.5f);
      _bg[1].setPosition(125 , 240);
    }
    void GSLose2 ::   Update(float deltaTime){
      for (auto btn : m_ListBtn) {
	    	btn->Update(deltaTime);
	    }
    }

    void GSLose2 ::   Render(RenderWindow* window){
      window->draw(_bg[0]);
      window->draw(_bg[1]);

	    for (auto btn : m_ListBtn) {
		    btn->Render(window);
    	}
    }