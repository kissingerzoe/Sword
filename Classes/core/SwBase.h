//ybzuo
//base
#ifndef __SW_BASE_H__
#define __SW_BASE_H__
#include "cocos2d.h"
#include "SwWorld.h"
class SwBase{
 public:
  SwBase(SwWorld* _sw);
  inline void set_pos(cocos2d::Point _pos){m_pos=_pos;m_sprite->setPosition(m_pos);}
  inline cocos2d::Point get_pos(){return m_pos;}
 private:
  SwWorld* m_world;
  cocos2d::Point m_pos;
  cocos2d::Sprite* m_sprite; 
};
#endif
