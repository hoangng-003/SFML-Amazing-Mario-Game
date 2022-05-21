#include "Animation.h"

Animation:: Animation(Texture &texture , Vector2i frameNum){
  _frameNum = frameNum;
  this->setTexture(texture);

  _currentFrame = Vector2i(0,0);

  caculateRectSize();
  caculateRectUV();
  applyRect();
}

void Animation:: caculateRectSize(){
  _rectSize = Vector2i (this->getTexture()->getSize().x / _frameNum.x , this->getTexture()->getSize().y / _frameNum.y);
}

void Animation:: caculateRectUV(){
  _rectUV.x = _currentFrame.x*_rectSize.x;
  _rectUV.y = _currentFrame.y*_rectSize.y;
}

void Animation:: applyRect(){
  _rect = IntRect(_rectUV,_rectSize);
  this->setTextureRect(_rect);
}

void Animation:: update(){
  if(Keyboard::isKeyPressed(Keyboard::Left)){
    _currentFrame.y = 0;
    _currentFrame.x++;
    if ( _currentFrame.x == _frameNum.x ) _currentFrame.x = 0;
  }else if(Keyboard::isKeyPressed(Keyboard::Right)){
    _currentFrame.y = 1;
    _currentFrame.x++;
    if ( _currentFrame.x == _frameNum.x ) _currentFrame.x = 0;
  }else{
    _currentFrame.x = 0;
  }
    caculateRectUV();
    applyRect();

}