//ybzuo
#include "SwWorld.h"
#include "SwBase.h"
#include "SwMap.h"
USING_NS_CC;
SwWorld::SwWorld(cocos2d::Layer* _layer){
  m_layer=_layer;
}
void SwWorld::init(){
  SwBase* _sb=new SwBase(this);
  m_sprite_list.push_back(_sb);
  m_hero=_sb;
  m_map=new SwMap(this);
}

void SwWorld::add_sprite(cocos2d::Sprite* _s){
  m_layer->addChild(_s);
}
void SwWorld::update(float _d){
  if(m_key_left){
    Point _p=m_hero->get_pos();
    m_hero->set_pos(_p+Point(-mc_speed*_d,0)); 
  }
  if(m_key_right){
    Point _p=m_hero->get_pos();
    m_hero->set_pos(_p+Point(mc_speed*_d,0));
  }
  if(m_key_up){
     Point _p=m_hero->get_pos();
     m_hero->set_pos(_p+Point(0,mc_speed*_d));
  }
  if(m_key_down){
    Point _p=m_hero->get_pos();
    m_hero->set_pos(_p+Point(0,-mc_speed*_d));
  }
}


void SwWorld::on_key_pressed(EventKeyboard::KeyCode keyCode)
{
  switch(keyCode){
  default:
    break;
  case EventKeyboard::KeyCode::KEY_LEFT_ARROW:{
    m_key_left=true;
  }
    break;
  case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:{
    m_key_right=true;
  }
    break;
  case EventKeyboard::KeyCode::KEY_UP_ARROW:{
    m_key_up=true;
  }
    break;
  case EventKeyboard::KeyCode::KEY_DOWN_ARROW:{
    m_key_down=true;
  }
    break;
  }
}

void SwWorld::on_key_released(EventKeyboard::KeyCode keyCode)
{
  switch(keyCode){
  default:
    break;
  case EventKeyboard::KeyCode::KEY_LEFT_ARROW:{
    m_key_left=false;
  }
    break;
  case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:{
    m_key_right=false;
  }
    break;
  case EventKeyboard::KeyCode::KEY_UP_ARROW:{
    m_key_up=false;
  }
    break;
  case EventKeyboard::KeyCode::KEY_DOWN_ARROW:{
    m_key_down=false;
  }
    break;
  case EventKeyboard::KeyCode::KEY_SPACE:{
    m_map->next_wave();
  }
    break;
  }
  
}



