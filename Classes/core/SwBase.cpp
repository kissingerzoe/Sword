//ybzuo
#include "SwBase.h"
USING_NS_CC;
SwBase::SwBase(SwWorld* _sw){
  m_world=_sw;
  m_pos.x=200;
  m_pos.y=300;
  m_sprite = Sprite::create("hero.png");
    m_sprite->setPosition(m_pos);
    m_world->add_sprite(m_sprite);
  // position the sprite on the center of the screen
}
