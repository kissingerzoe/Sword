//ybzuo
#include "SwBase.h"
USING_NS_CC;
SwBase::SwBase(SwWorld* _sw){
  m_world=_sw;
  m_pos.x=200;
  m_pos.y=300;
  m_sprite = Sprite::create("hero.png");
  m_sprite->retain();
  m_tex_rect=m_sprite->getTextureRect();
  m_sprite->setPosition(m_pos);
  //  m_world->add_sprite(this);
  m_shape=new b2PolygonShape();
  // m_shap
  // position the sprite on the center of the screen
}
void SwBase::set_pos(cocos2d::Point _pos){
  m_pos=_pos;
  m_sprite->setPosition(m_pos);
  b2Vec2 _c;
  _c.x=m_pos.x;
  _c.y=m_pos.y;
  m_shape->SetAsBox(m_tex_rect.size.width,m_tex_rect.size.height,_c,0.0f);
}
void SwBase::hurt(int _damage){
  m_life-=_damage;
  if(m_life<=0){
    //dead;
    m_world->remove_sprite(this);
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
