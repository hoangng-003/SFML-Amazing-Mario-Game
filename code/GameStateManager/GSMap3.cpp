#include "GSMap3.h"
    
  GSMap3 ::  GSMap3(){

  }
    GSMap3 :: ~GSMap3(){

    }

    void GSMap3 ::   Exit(){

    }
    void GSMap3 ::   Pause(){

    }
    void GSMap3 ::   Resume(){

    }

    void GSMap3 ::   Init(){
      shape.setSize(Vector2f(200.f,200.f));
      shape.setFillColor(Color::Blue);
      shape.setPosition(200 , 200);
    }
    void GSMap3 ::   Update(float deltaTime){

    }

    void GSMap3 ::   Render(RenderWindow* window){
        window->draw(shape);
    }