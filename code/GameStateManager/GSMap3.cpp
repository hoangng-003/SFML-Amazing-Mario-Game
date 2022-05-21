#include "GSMap3.h"
    
        float marioSpeed3 = 200.f;
        float mass3 = 10;
        float jumpF3=150;
        float jumpSpeed3;
        float gravity3 = 9.8;

      bool isJumping3 = false;
      bool isDrop = true;
      bool isCheck0 = false;
      bool isCheck1 = false;


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
      isJumping3 = false;
      isDrop = true;
      isCheck0 = false;
      isCheck1 = false;

      _mario = new Animation(*DATA->getTexture("marioS"), Vector2i(10,2));
      (*_mario).setPosition(20,67);
      (*_mario).setScale(0.5f , 0.5f);

      setSprite(DATA->getTexture("map3"), -90 , 0 , 0);
      _sprite[0].setScale(1.f,1.1f);

      setSprite(DATA->getTexture("princess"), WIDTH + 100 , HEIGHT - 290 , 1);
      _sprite[1].setScale(0.15f,0.15f);


      _checkPoint[0].setPosition(0, HEIGHT-105);
      _checkPoint[0].setSize( Vector2f(50.f,50.f));

      _checkPoint[1].setPosition(WIDTH-97, HEIGHT/2 - 10);
      _checkPoint[1].setSize( Vector2f(50.f,50.f));

    }
    void GSMap3 ::   Update(float deltaTime){
      Vector2f pos = (*_mario).getPosition();

        // Mario Move

        if(Keyboard::isKeyPressed(Keyboard::Left)){
          if(pos.x - marioSpeed3*deltaTime <= 0){
           (*_mario).setPosition(0 , pos.y);
          }
          else (*_mario).move(-marioSpeed3 * deltaTime , 0);
        }else if(Keyboard::isKeyPressed(Keyboard::Right)){
          if(pos.x + marioSpeed3*deltaTime > WIDTH - 40 ) (*_mario).setPosition(WIDTH-40 , pos.y);
          else (*_mario).move(marioSpeed3 * deltaTime , 0);
        }

        // Mario rơi
        if(isDrop) (*_mario).move(0, marioSpeed3*deltaTime*2);
      
        // Mario Jump

        if(Keyboard::isKeyPressed(Keyboard::Space) && !isJumping3){
            jumpSpeed3 = jumpF3 / mass3;
            isJumping3 = true;
        }
        if(isJumping3){
            jumpSpeed3 -= gravity3*deltaTime*2;
            (*_mario).move(0, -jumpSpeed3);
        }

        if(jumpSpeed3 < 0){
            isJumping3 = false;
        }

        // logic 

        if((pos.y > HEIGHT - 113 && pos.y < HEIGHT - 100 && pos.x < 90) 
        || (pos.y > HEIGHT - 190 && pos.y < HEIGHT - 170 && pos.x > 25 && pos.x < 170)
        || (pos.y > 66 && pos.y < 80 && pos.x > 19 && pos.x < 160 ) 
        || (pos.y > HEIGHT - 190 && pos.y < HEIGHT - 170 && pos.x > 270 && pos.x < 440)
        || (pos.y > HEIGHT - 290 && pos.y < HEIGHT - 240 && pos.x > 340)
        || (pos.y > 10 && pos.y < 30 && pos.x > 270 && pos.x < 440)
        ){
          isDrop = false;
        }else{
          isDrop = true;
        }

        FloatRect shapeM = (*_mario).getGlobalBounds();
        FloatRect shapeK = _checkPoint[0].getGlobalBounds();
        FloatRect shapeC = _checkPoint[1].getGlobalBounds();
        FloatRect shapeP = _sprite[1].getGlobalBounds();


        if(shapeM.intersects(shapeK)) isCheck0 = true;

        if(shapeM.intersects(shapeC) && isCheck0) isCheck1 = true;

        if(isCheck0 && isCheck1){
          _sprite[1].move(-marioSpeed3*deltaTime/2,0);
        }

        if(shapeM.intersects(shapeP)){
          GSM->ChangeState(StateTypes::VICTORY);
        }

        if(pos.y > HEIGHT){
          GSM->ChangeState(StateTypes::LOSE3);
        }

                (*_mario).update();
    }

    void GSMap3 ::   Render(RenderWindow* window){
        window->draw (_checkPoint[0]);
        window->draw (_checkPoint[1]);
        window->draw (_sprite[0]);
        window->draw (_sprite[1]);
        window->draw (*_mario);
    }

    void GSMap3 :: setSprite(Texture* texture, float posx , float posy, int i){
    _sprite[i].setTexture(*texture);
    _sprite[i].setPosition(posx , posy);
  }
