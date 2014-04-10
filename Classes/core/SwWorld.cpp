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
  // m_sprite_list.push_back(_sb);
  m_hero=_sb;
  m_map=new SwMap(this);
  add_sprite(m_hero);
}

void SwWorld::add_sprite(SwBase* _sb){
  m_add_list.push_back(_sb);
}

void SwWorld::remove_sprite(SwBase* _sb){
  if(_sb==NULL){return;}
  for(int i=0;i<m_sprite_list.size();++i){
    if(m_sprite_list[i]==_sb){
      m_remove_list.push_back(i);
    }
  }
}


void SwWorld::update(float _d){
  //input
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
  //logic
  m_map->update(_d);
  //life
  if(m_remove_list.size()>0){
    for(int _i=0;_i<m_remove_list.size();++_i){
      m_layer->removeChild(m_sprite_list[m_remove_list[_i]]->get_coco_sprite());
      delete m_sprite_list[m_remove_list[_i]];
      m_sprite_list[m_remove_list[_i]]=NULL;
    }
    m_remove_list.clear();
  }
  if(m_add_list.size()>0){
    for(int _i=0;_i<m_add_list.size();++_i){
      m_sprite_list.push_back(m_add_list[_i]);
      m_layer->addChild(m_add_list[_i]->get_coco_sprite());    
    }
    m_add_list.clear();
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
    break;
  }
  }
}

void SwWorld::on_key_released(EventKeyboard::KeyCode keyCode){
  switch(keyCode){
  default:
    break;
  case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
    m_key_left=false;
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
    shot();
  }
    break;
  }
}

void SwWorld::shot(){
  b2Transform transform;
  transform.SetIdentity();
  b2RayCastInput _input;
  _input.p1.Set(m_hero->get_pos().x,m_hero->get_pos().y);
  _input.p2.Set(m_hero->get_pos().x,m_hero->get_pos().y+10000.0f);
  _input.maxFraction=1.0f;
  int32 childIndex=0;
  b2RayCastOutput output;
  for(int i=0;i<m_sprite_list.size();++i){
    if(m_sprite_list[i]==NULL){continue;}
    if(m_sprite_list[i]!=m_hero){
      bool hit=m_sprite_list[i]->get_b2poly()->RayCast(&output,_input,transform,childIndex);
      if(hit){
	m_sprite_list[i]->hurt(1);
      }
    }
  }
}



