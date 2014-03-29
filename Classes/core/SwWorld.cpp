//ybzuo
#include "SwWorld.h"
#include "SwBase.h"
USING_NS_CC;
SwWorld::SwWorld(cocos2d::Layer* _layer){
  m_layer=_layer;
}
void SwWorld::init(){
  SwBase* _sb=new SwBase(this);
  m_sprite_list.push_back(_sb);
}

void SwWorld::add_sprite(cocos2d::Sprite* _s){
  m_layer->addChild(_s);
}
