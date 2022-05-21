#pragma once

#include "GameStateBase.h"
#include "../GameObjects/Animation/Animation.h"
class GSMap1 : public GameStateBase {
  public:
    GSMap1();
    virtual ~GSMap1();

    void Exit();
    void Pause();
    void Resume();

    void Init();
    void Update(float deltaTime);
    void Render(RenderWindow* window);

    void setSprite(Texture* texture, float posx , float posy , int i);
    void setSound(SoundBuffer* soundBuffer , bool isLoop);
    void setMusic(string path , bool isLoop);
    void setText(Font* font,string content, float posx , float posy , Color color, float fontSize, int i);

    private:
      Sound _sound;
      Sprite _sprite[10];
      RectangleShape _key;
      RectangleShape _wall;
      Music _music;
      Text _text;
      Animation* _mario;
};