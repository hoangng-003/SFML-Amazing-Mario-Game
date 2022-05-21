#include "GSMap1.h"
using namespace std;

        float marioSpeed = 200.f;
        float mushroomSpeed = 150.f;

        float jumpSpeed;
        float mass = 10;
        bool isJumping = false;
        float jumpF=100;
        float gravity = 9.8;

        bool isMushroomRun = false;
        bool isStoneDown = false;
        bool isUsingKey = false;
        bool isW1Run = false;

        float sizeBase = 1.f;
        float sizePipeBase = 1.f;
        bool isScale = false;
        bool isScaleAgain = false;
        bool isPipeScale = false;
        int k=0;

    
  GSMap1 ::  GSMap1(){}
  GSMap1 :: ~GSMap1(){}
  void GSMap1 ::   Exit(){}
  void GSMap1 ::   Pause(){}
  void GSMap1 ::   Resume(){}

    void GSMap1 ::   Init(){
      _mario = new Animation(*DATA->getTexture("marioS"), Vector2i(10,2));
      (*_mario).setPosition(150,bottom);
      (*_mario).setScale(0.5f , 0.5f);

      setText(DATA->getFont("ARCADE") , "Jump to the left \n of the first block" , -300 , 0 , Color::Black , 24 , 0 );


      setSprite(DATA->getTexture("menubg"), 0 , 0 , 0);
      _sprite[0].setScale(3.f,4.f);

      setSprite(DATA->getTexture("mushroom"), -300 , 0, 1);
      _sprite[1].setScale(0.05f,0.05f);

        setSprite(DATA->getTexture("spikes"), -300 , 0 , 2);
      _sprite[2].setScale(0.45f,0.22f);
      _sprite[2].rotate(180);

      setSprite(DATA->getTexture("pipem1"), WIDTH - 100 , HEIGHT/2 + 60 , 3);
      _sprite[3].setScale(0.3f,0.7f);
      int i = 4;
      while(i<7){
        setSprite(DATA->getTexture("wall"), WIDTH/2 - 50 + 50*(i-4) , HEIGHT/2 + 25 , i);
        i++;  
      }

      _wall.setPosition(-300, 0);
      _wall.setSize( Vector2f(50.f,200.f));

      _key.setPosition(WIDTH/2 - 100, HEIGHT/2 + 25);
      _key.setSize( Vector2f(50.f,50.f));

      setSprite(DATA->getTexture("stone"), 20 , -300 , 7);
      _sprite[7].setScale(0.08f,0.08f);
      
      setSprite(DATA->getTexture("bottomWall"), 0 , HEIGHT - 25 , 8);

      setSprite(DATA->getTexture("ufo"), -300 , 100 , 9);
      _sprite[9].setScale(0.05f,0.05f);

      isJumping = false;
      isMushroomRun = false;
      isStoneDown = false;
      isUsingKey = false;
      isW1Run = false;
      isScale = false;
      isScaleAgain = false;
      isPipeScale = false;

    }

    void GSMap1 ::   Update(float deltaTime){

      Vector2f pos = (*_mario).getPosition();
      Vector2f mrPos = _sprite[1].getPosition();

        // Mario Jump

        if(Keyboard::isKeyPressed(Keyboard::Space) && !isJumping){
            jumpSpeed = jumpF / mass;
            isJumping = true;
        }
        if(isJumping){
            jumpSpeed -= gravity*deltaTime*2;
            (*_mario).move(0, -jumpSpeed);

            if(pos.y>bottom){
                (*_mario).setPosition(pos.x,bottom);
                isJumping = false;
            }
        }

        // Mario Move

        if(Keyboard::isKeyPressed(Keyboard::Left)){
          if(pos.x - marioSpeed*deltaTime <= 0){
           (*_mario).setPosition(0 , pos.y);
           isStoneDown = true;
          }
          else (*_mario).move(-marioSpeed * deltaTime , 0);
        }else if(Keyboard::isKeyPressed(Keyboard::Right)){
          if(pos.x + marioSpeed*deltaTime > WIDTH - 100 - 50 ) (*_mario).setPosition(WIDTH-100-60 , pos.y);
          else (*_mario).move(marioSpeed * deltaTime , 0);
        }

        // Xu ly 1 dong thu , can cleanCode

        if(isStoneDown){
           _sprite[7].move(0 , mushroomSpeed*deltaTime*8);
        }

        if(pos.x >= WIDTH/2 -50)_text.setPosition(175 , 175);
            else _text.setPosition(-300 , 0);

        if(!isUsingKey && ((pos.x >= WIDTH/2 -50 && pos.x <= WIDTH/2 + 100 && pos.y >= HEIGHT/2 + 25 && pos.y <= HEIGHT/2 + 75)
         || (pos.x >= WIDTH/2 + 50)
        )){
          _sprite[2].setPosition(WIDTH/2 + 99 , HEIGHT/2 + 110);
          _wall.setPosition(WIDTH/2 + 100, HEIGHT/2 + 75);

        }
        if(isUsingKey){
          _sprite[2].setPosition(-300 , HEIGHT/2 + 110);
          _wall.setPosition(-300, HEIGHT/2 + 75);
        }
        if(isW1Run){
            _sprite[4].move(0, -mushroomSpeed*deltaTime);
        }

        if(_sprite[4].getPosition().y <= HEIGHT/2 -25 && isW1Run == true){
            _sprite[4].setPosition(-300 , 0);
            _sprite[1].setPosition(WIDTH/2 - 50 , HEIGHT/2 - 25 );
            isMushroomRun = true;
            isW1Run = false;
        }

        if(isMushroomRun){
          if(mrPos.x + mushroomSpeed*deltaTime > WIDTH/2 + 100 && mrPos.y + mushroomSpeed*deltaTime < HEIGHT - 75 ){
            _sprite[1].move(0,mushroomSpeed * deltaTime);
          }else{
            _sprite[1].move(mushroomSpeed/2 * deltaTime , 0);
          }
        }

        if(_sprite[9].getPosition().x >= WIDTH){
          GSM->ChangeState(StateTypes::MAP2);
        }

        // Scaling after eat mushroom

        if(pos.y <= 50){
          isScale = false;
          (*_mario).setPosition( pos.x, pos.y );
          _sprite[9].move(mushroomSpeed*deltaTime,0);
        }

        if(isScale){
          sizeBase += marioSpeed*deltaTime/200;
          pos.x -= marioSpeed*deltaTime/2;
          pos.y -= marioSpeed*deltaTime/2;
          (*_mario).setScale( sizeBase, sizeBase );
          (*_mario).setPosition( pos.x, pos.y );
        }

        if(isScaleAgain){
          sizeBase -= marioSpeed*deltaTime/200;
          (*_mario).setScale( sizeBase, sizeBase );
        }

        if(sizeBase <= 50.f){
          isScaleAgain = false;
        }

        if(isPipeScale){
          sizePipeBase += marioSpeed*deltaTime/200;
          k++;
          _sprite[3].setScale( sizePipeBase, sizePipeBase );
          _sprite[3].setPosition( WIDTH - 100 - k*marioSpeed*deltaTime/10  , HEIGHT/2 + 60 - k*marioSpeed*deltaTime/2 );
        }

        if(_sprite[3].getPosition().y < 100){
          isPipeScale = false;
          _sprite[3].rotate(-5);
        }

        // Xu ly va cham

        FloatRect shapeM = (*_mario).getGlobalBounds();
        FloatRect shapeMR = _sprite[1].getGlobalBounds();
        FloatRect shapeK = _key.getGlobalBounds();
        FloatRect shapeW1 = _sprite[4].getGlobalBounds();
        FloatRect shapeW = _wall.getGlobalBounds();
        FloatRect shapeSt = _sprite[7].getGlobalBounds();
        FloatRect shapeSp = _sprite[2].getGlobalBounds();
        FloatRect shapeP = _sprite[3].getGlobalBounds();
        FloatRect shapePl = _sprite[9].getGlobalBounds();
        
        if(shapeM.intersects(shapeMR)){
            _sprite[1].setPosition(-300 , 0); 
            isMushroomRun = false;
            isScale = true;
            _sprite[3].setPosition(0 , -300); 
        }

        if(shapeM.intersects(shapeP)){
          GSM->ChangeState(StateTypes::LOSE);
        }

        if(shapeMR.intersects(shapeP)){
            _sprite[1].setPosition(-300 , 0); 
            isMushroomRun = false ;
            isPipeScale = true;
        }

        if(shapeM.intersects(shapeW1)){
          isW1Run = true;
        }

        if(shapeM.intersects(shapePl)){
            _sprite[9].setPosition(pos.x , pos.y-25);
            isScaleAgain = true;
        }

        if(shapeM.intersects(shapeW)){
          (*_mario).setPosition(WIDTH/2 + 50 , pos.y);
        }

        if(shapeM.intersects(shapeSt) || shapeM.intersects(shapeSp) ){
          GSM->ChangeState(StateTypes::LOSE);
        }

        if(shapeM.intersects(shapeK)){
          isUsingKey = true;
        }

        (*_mario).update();
    }

    void GSMap1 ::   Render(RenderWindow* window){
        window->draw (_wall);
        window->draw (_key);
        window->draw (_sprite[0]);
        window->draw (_sprite[1]);
        window->draw (_sprite[2]);
        window->draw (_sprite[3]);
        window->draw (_sprite[4]);
        window->draw (_sprite[5]);
        window->draw (_sprite[6]);
        window->draw (*_mario);
        window->draw (_sprite[7]);
        window->draw (_sprite[8]);
        window->draw (_sprite[9]);
        window->draw(_text);
    }

    // Set up Resources

  void GSMap1 :: setSprite(Texture* texture, float posx , float posy, int i){
    _sprite[i].setTexture(*texture);
    _sprite[i].setPosition(posx , posy);
  }

  void GSMap1 :: setSound(SoundBuffer* soundBuffer , bool isLoop){
    _sound.setBuffer(*soundBuffer);
    _sound.play();
    _sound.setLoop(isLoop);
  }

  void GSMap1 :: setMusic(string path , bool isLoop){
    _music.openFromFile(path);
    _music.play();
    _music.setLoop(isLoop);
  }

  void GSMap1 :: setText(Font* font,string content, float posx , float posy , Color color, float fontSize, int i){
    _text.setFont(*font);
    _text.setString(content);
    _text.setPosition(posx,posy);
    _text.setFillColor(color);
    _text.setCharacterSize(fontSize);
  }
