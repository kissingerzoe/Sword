#include "SwWeapon.h"
#include "SwbPoint.h"
#include "SwBase.h"
USING_NS_CC;
SwWeapon::SwWeapon(SwWorld* _w,SwBase* _base){
  m_world=_w;
  m_owner=_base;
}
void SwWeapon::shot(){
  if(m_cd<=0){
    real_shot();
    m_cd=m_interal;
  }
}
void SwWeapon::update(float _d){
  if(m_cd>0.0f){
    m_cd-=_d;
  }
}
void SwWeapon::real_shot(){
  // for(int i=0;i<2;++i){
  // SwbPoint* _p=new SwwPoint(this,m_hero,Point(-200+rand()%400,600));
  SwbPoint* _p=new SwbPoint(m_world,m_owner,Point(0,m_speed));
  _p->set_pos(m_owner->get_pos()+Point(0,10));
  m_world->add_sprite(_p);
  // }
}
