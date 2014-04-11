#include "SwSpriteUnit.h"
#include <cstdlib>
#include "SwBase.h"
#include "SwWorld.h"
USING_NS_CC;
SwSpriteUnit::SwSpriteUnit(SwWorld* _s){
  begin_time=1.0f;
  begin_pos=Point(100+rand()%100,200+rand()%300);
  m_world=_s;
}
bool SwSpriteUnit::update(float _d){
  if(begin_time>0.0f){
    begin_time-=_d;
    if(begin_time<=0.0f){
      begin_time=-1.0f;
      appear();
    }
    return false;
  }else{
    return sprite->get_life()<=0;
  }
}
void SwSpriteUnit::appear(){
  sprite=new SwBase(m_world);
  sprite->set_pos(begin_pos);
  sprite->set_rotate(180.0f);
  m_world->add_sprite(sprite);
}
