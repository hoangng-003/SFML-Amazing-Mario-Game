#include "GSMap2.h"
    
      bool isPipe3Up = false;
      bool isPipe10Down = false;
      bool isPipe9Run1 = false;
      bool isPipe9Run2 = false;
      bool isPipe9Rotate = false;
      bool isPipe3Down = false;
      bool isPipe8Down = false;
      bool check = true;


  GSMap2 ::  GSMap2(){}
  GSMap2 :: ~GSMap2(){}
  void GSMap2 ::   Exit(){}
  void GSMap2 ::   Pause(){}
  void GSMap2 ::   Resume(){}

    void GSMap2 ::   Init(){
      setSprite(DATA->getTexture("menubg"), 0 , 0 , 0);
      _sprite[0].setScale(3.f,4.f);

      setSprite(DATA->getTexture("ufo"), 2 , HEIGHT/2 , 1);
      _sprite[1].setScale(0.05f,0.05f);

      int i=2;
      while(i <= 8){
        setSprite(DATA->getTexture("pipe"), WIDTH/3 + 140*(i/2 - 1) - 65 , 150 , i);
        _sprite[i].rotate(180);
        _sprite[i].setScale(0.13f , 0.55f);
        i+=2;
      }
      int j=3;
      while(j <= 9){
        setSprite(DATA->getTexture("pipe"), WIDTH/3 + 140*(j/2-1.75) - 30 + 3 , HEIGHT - 150 , j);
        _sprite[j].setScale(0.13f , 0.55f);
        j+=2;
      }

      _sprite[4].setPosition(WIDTH/3 + 140 - 72 , HEIGHT/2 );
      _sprite[7].setPosition(WIDTH/3 + 140*(7/2 - 1.75) - 27 , HEIGHT/2 );
      setSprite(DATA->getTexture("pipe"), WIDTH/3 , -300 , 10);
      _sprite[10].rotate(180);
      _sprite[10].setScale(0.13f , 0.55f);

      setSprite(DATA->getTexture("finish"), WIDTH - 70 , 200 , 11);
      _sprite[11].setScale(0.15f,0.15f);

      isPipe3Up = false;
      isPipe10Down = false;
      isPipe9Run1 = false;
      isPipe9Run2 = false;
      isPipe9Rotate = false;
      isPipe3Down = false;
      isPipe8Down = false;
      check = true;
    }
    void GSMap2 ::   Update(float deltaTime){

      Vector2f pos = _sprite[1].getPosition();
      float marioSpeed = 200.f;      

        // Flying

        if(Keyboard::isKeyPressed(Keyboard::Left)){

          if(pos.x - marioSpeed*deltaTime <= 0) _sprite[1].setPosition(0 , pos.y);
          else _sprite[1].move(-marioSpeed * deltaTime , 0);

        }else if(Keyboard::isKeyPressed(Keyboard::Right)){

          if(pos.x + marioSpeed*deltaTime >= WIDTH - 40 ) _sprite[1].setPosition(WIDTH - 40 , pos.y);
          else _sprite[1].move(marioSpeed * deltaTime , 0);

        }else if(Keyboard::isKeyPressed(Keyboard::Up)){

          if(pos.y - marioSpeed*deltaTime <= 0 ) _sprite[1].setPosition(pos.x , 0);
          else _sprite[1].move(0, -marioSpeed * deltaTime);
          
        }else if(Keyboard::isKeyPressed(Keyboard::Down)){

          if(pos.y + marioSpeed*deltaTime >= HEIGHT-40 ) _sprite[1].setPosition(pos.x , HEIGHT-40);
          else _sprite[1].move(0, marioSpeed * deltaTime);
          
        }

        // Pipe Running

      if(pos.x >= WIDTH/3 - 10){
        isPipe10Down = true;
      }

      if(isPipe10Down){
        _sprite[10].move(0, marioSpeed * deltaTime*8);
      }

      if(pos.x >= WIDTH/3 + 100 && _sprite[9].getPosition().y > HEIGHT/2 - 75){
        isPipe9Run1 = true;
      }

      if(isPipe9Run1){
        _sprite[9].move(0, -marioSpeed * deltaTime);
      }

      if(pos.x >= WIDTH/3 - 170 && !isPipe3Down ){
        isPipe3Up = true;
      }

      if(isPipe3Up){
        _sprite[3].move(0 , -marioSpeed * deltaTime*3);
      }

      if(_sprite[3].getPosition().y < HEIGHT/2 - 75){
        _sprite[3].setPosition(_sprite[3].getPosition().x , HEIGHT/2 - 74);
        isPipe3Up = false;
        isPipe3Down = true;
      }

      if(isPipe3Down){
        _sprite[3].move(0 , marioSpeed * deltaTime*3);
      }

      if(_sprite[9].getPosition().y <= HEIGHT/2 - 75 && check ){
        isPipe9Run1 = false;
        _sprite[9].setPosition(_sprite[9].getPosition().x , HEIGHT/2 - 75);
        isPipe9Rotate = true;
        isPipe9Run2 = true;
        check = false;
      }
      if(isPipe9Rotate){
        _sprite[9].rotate(90);
        isPipe9Rotate = false;
      }

      if(isPipe9Run2){
        _sprite[9].move(-marioSpeed * deltaTime , 0);       
      }

      if(pos.x >= WIDTH/3 + 240){
        isPipe8Down = true;
      }

      if(isPipe8Down){
        _sprite[8].move(0, marioSpeed * deltaTime*2);
      }

      FloatRect shapeM = _sprite[1].getGlobalBounds();
      FloatRect shapeWin = _sprite[11].getGlobalBounds();
      FloatRect shapeP[9];
      for( int i=0;i<9;i++){
        shapeP[i] = _sprite[i+2].getGlobalBounds();
        if(shapeM.intersects(shapeP[i])){
          GSM->ChangeState(StateTypes::LOSE2);
        }
      }

      if(shapeM.intersects(shapeWin)){
          GSM->ChangeState(StateTypes::MAP3);
      }

    }

    void GSMap2 ::   Render(RenderWindow* window){
      window->draw(_sprite[0]);
      window->draw(_sprite[1]);
      window->draw(_sprite[2]);
      window->draw(_sprite[3]);
      window->draw(_sprite[4]);
      window->draw(_sprite[5]);
      window->draw(_sprite[6]);
      window->draw(_sprite[7]);
      window->draw(_sprite[8]);
      window->draw(_sprite[9]);
      window->draw(_sprite[10]);   
      window->draw(_sprite[11]);   
    }

    void GSMap2 :: setSprite(Texture* texture, float posx , float posy, int i){
    _sprite[i].setTexture(*texture);
    _sprite[i].setPosition(posx , posy);
  }