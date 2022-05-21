#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Animation: public Sprite{
  public:
    Animation(Texture &texture , Vector2i frameNum);
    void caculateRectSize();
    void caculateRectUV();
    void applyRect();
    void update();
  private:
    Vector2i _frameNum;
    Vector2i _currentFrame;

    Vector2i _rectUV;
    Vector2i _rectSize;
    IntRect _rect;
};