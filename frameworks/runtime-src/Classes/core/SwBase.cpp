//ybzuo
#include "SwBase.h"
#include "SwWeapon.h"
#include <cstdlib>
USING_NS_CC;
SwBase::SwBase(SwWorld* _sw){
  m_world=_sw;
  init("ma.png");
}
SwBase::SwBase(SwWorld* _sw,string _idle,string _shot){
  m_world=_sw;
  init(_idle);
  m_idle_p=_idle;
  m_shot_p=_shot;
}
void SwBase::init(string _file){
  m_sprite = Sprite::create(_file);
  m_sprite->retain();
  m_tex_rect=m_sprite->getTextureRect();
  m_shape=new b2PolygonShape();
  m_life=rand()%5+1;
}


void SwBase::set_pos(cocos2d::Point _pos){
  m_pos=_pos;
  m_sprite->setPosition(m_world->fix_pos(m_pos));
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
void SwBase::shot(){
  if(m_weapon!=NULL){
    m_weapon->shot();
    m_sprite->setTexture(m_shot_p);
    m_in_shot_tick=mc_shot_time;
  }
}
void SwBase::update(float _d){
  if(m_weapon!=NULL){
    m_weapon->update(_d);
    if(m_in_shot_tick>0.0f){
      m_in_shot_tick-=_d;
      if(m_in_shot_tick<=0.0f){
	m_in_shot_tick=-1.0f;
	m_sprite->setTexture(m_idle_p);
      }
    }
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
