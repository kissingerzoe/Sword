//ybzuo
#include "SwBase.h"
USING_NS_CC;
SwBase::SwBase(SwWorld* _sw){
  m_world=_sw;
  m_sprite = Sprite::create("hero.png");
  if(m_sprite!=NULL){
    m_sprite->setPosition(Point(300.0f,300.0f));
    m_world->add_sprite(m_sprite);
  }else{
    
  }
  // position the sprite on the center of the screen

}
