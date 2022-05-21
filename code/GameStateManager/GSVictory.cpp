#include "GSVictory.h"
    
  GSVictory ::  GSVictory(){

  }
    GSVictory :: ~GSVictory(){

    }

    void GSVictory ::   Exit(){

    }
    void GSVictory ::   Pause(){

    }
    void GSVictory ::   Resume(){

    }

    void GSVictory ::   Init(){

      GameButton* button;

      //Play Again
	    button = new GameButton();
	    button->Init("playagain");
	    button->setOnClick([]() {GSM->ChangeState(StateTypes::MENU); });
	    button->setPosition( 300 , HEIGHT - 70);
	    button->setSize(sf::Vector2f(150,50));
	    button->setOrigin(button->getSize() / 2.f);
	    m_ListBtn.push_back(button);

      _bg.setTexture(*DATA->getTexture("victory"));
      _bg.setPosition(-100, -200);
      
    }
    void GSVictory ::   Update(float deltaTime){
      for (auto btn : m_ListBtn) {
	    	btn->Update(deltaTime);
	    }
    }

    void GSVictory ::   Render(RenderWindow* window){
      window->draw(_bg);

	    for (auto btn : m_ListBtn) {
		    btn->Render(window);
    	}
    }