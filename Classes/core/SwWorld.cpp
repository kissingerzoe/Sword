//ybzuo
#include "SwWorld.h"
#include "SwBase.h"
#include "SwMap.h"
#include "SwbPoint.h"
#include "SwWeapon.h"
#include <cstdlib>
USING_NS_CC;
SwWorld::SwWorld(cocos2d::Layer* _layer){
  m_layer=_layer;
  m_size = Director::getInstance()->getVisibleSize();
  m_half_size.x=m_size.width*0.5f;
  m_half_size.y=0.0f;
  m_origin = Director::getInstance()->getVisibleOrigin();
}
void SwWorld::init(){
  SwBase* _sb=new SwBase(this,"dao.png");
  m_hero=_sb;
  m_hero->take_weapon(new SwWeapon(this,m_hero));
  m_hero->set_pos(Point(0,50));
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
  if(m_key_shot){
    shot();
  }
  //  CCLog("x:%f,y:%f",m_hero->get_pos().x,m_hero->get_pos().y);
  //logic
  m_map->update(_d);
  for(int i=0;i<m_sprite_list.size();++i){
    if(m_sprite_list[i]!=NULL){
      m_sprite_list[i]->update(_d);
    }
  }
  for(int i=0;i<m_sprite_list.size();++i){
    if(m_sprite_list[i]!=NULL){
      for(int j=0;j<m_sprite_list.size();++j){
	if(i!=j){
	  if(m_sprite_list[j]!=NULL){
	    m_sprite_list[i]->collide_update(m_sprite_list[j]);
	  }
	}
      }
    }
  }
  //life
  if(m_remove_list.size()>0){
    for(int _i=0;_i<m_remove_list.size();++_i){
      int _sid=m_remove_list[_i];
      SwBase* _sb=m_sprite_list[_sid];
      if(_sb!=NULL){
	if(_sb->get_coco_sprite()!=NULL){
	  m_layer->removeChild(m_sprite_list[_sid]->get_coco_sprite());
	}
	delete _sb;
	_sb=NULL;
      }
      m_sprite_list[_sid]=NULL;
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
  case EventKeyboard::KeyCode::KEY_A:{
    m_key_left=true;
  }
    break;
  case EventKeyboard::KeyCode::KEY_D:{
    m_key_right=true;
  }
    break;
  case EventKeyboard::KeyCode::KEY_W:{
    m_key_up=true;
  }
    break;
  case EventKeyboard::KeyCode::KEY_S:{
    m_key_down=true;
    break;
  }
  case EventKeyboard::KeyCode::KEY_SPACE:{
    m_key_shot=true;
    break;
  }
  }
}

void SwWorld::on_key_released(EventKeyboard::KeyCode keyCode){
  switch(keyCode){
  default:
    break;
  case EventKeyboard::KeyCode::KEY_A:
    m_key_left=false;
    break;
  case EventKeyboard::KeyCode::KEY_D:{
    m_key_right=false;
  }
    break;
  case EventKeyboard::KeyCode::KEY_W:{
    m_key_up=false;
  }
    break;
  case EventKeyboard::KeyCode::KEY_S:{
    m_key_down=false;
    break;
  }
  case EventKeyboard::KeyCode::KEY_SPACE:{
    m_key_shot=false;
    break;
  }
  }
}

void SwWorld::shot(){
  m_hero->shot();
  return;
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
      if(m_sprite_list[i]->get_b2poly()!=NULL){
	bool hit=m_sprite_list[i]->get_b2poly()->RayCast(&output,_input,transform,childIndex);
	if(hit){
	  m_sprite_list[i]->hurt(1);
	}
      }
    }
  }
}



