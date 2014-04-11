//ybzuo
#include "SwBase.h"
#include <cstdlib>
USING_NS_CC;
SwBase::SwBase(SwWorld* _sw){
  m_world=_sw;
  m_sprite = Sprite::create("ma.png");
  m_sprite->retain();
  m_tex_rect=m_sprite->getTextureRect();
  m_shape=new b2PolygonShape();
  m_life=rand()%5+1;
}
void SwBase::set_pos(cocos2d::Point _pos){
  m_pos=_pos;
  m_sprite->setPosition(m_pos);
  if(m_shape!=NULL){
    b2Vec2 _c;
    _c.x=m_pos.x;
    _c.y=m_pos.y;
    m_shape->SetAsBox(m_tex_rect.size.width,m_tex_rect.size.height,_c,0.0f);
  }
}
void SwBase::set_rotate(float _rot){
  m_rotate=_rot;
  m_sprite->setRotation(m_rotate);
}

void SwBase::hurt(int _damage){
  m_life-=_damage;
  if(m_life<=0){
    //dead;
    m_world->remove_sprite(this);
  }else{
    set_pos(m_pos+Point(0,rand()%50));
  }
}
SwBase::~SwBase(){
  if(m_sprite!=NULL){
    m_sprite->release();
  }
  if(m_shape!=NULL){
    delete m_shape;
    m_shape=NULL;
  }
}
