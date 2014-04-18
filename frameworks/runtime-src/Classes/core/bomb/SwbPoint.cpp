#include "SwbPoint.h"
#include "SwWorld.h"
USING_NS_CC;
SwbPoint::SwbPoint(SwWorld* _sw,SwBase* _owner,Point _speed):SwBase(_sw){
  m_world=_sw;
  m_owner=_owner;
  m_speed=_speed;
  m_sprite = Sprite::create("green_bow.png");
  m_sprite->retain();
  m_shape=NULL;
  m_life=1;
  m_damage=1;
  m_rotate=m_speed.getAngle();
  m_sprite->setRotation(m_rotate);
}

void SwbPoint::update(float _d){
  if(m_life_time>0.0f){
    m_life_time-=_d;
    if(m_life_time<=0.0f){
      m_life_time=-1.0f;
      m_world->remove_sprite(this);
    }  
  }
  set_pos(m_pos+m_speed*_d);
}

void SwbPoint::collide_update(SwBase* _d){
  if((_d==this)||(_d==m_owner)||(_d->get_b2poly()==NULL)){
    return;
  }
  b2Transform transform;
  transform.SetIdentity();
  if(_d->get_b2poly()->TestPoint(transform,b2Vec2(m_pos.x,m_pos.y))){
    m_world->remove_sprite(this);
    _d->hurt(m_damage);
  }
}

/*
void SwbPoint::update(){
  
}
*/
