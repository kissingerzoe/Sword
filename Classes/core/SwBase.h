//ybzuo
//base
#ifndef __SW_BASE_H__
#define __SW_BASE_H__
#include "cocos2d.h"
#include "SwWorld.h"
class SwBase{
 public:
  SwBase(SwWorld* _sw);
 private:
  SwWorld* m_world;
  cocos2d::Sprite* m_sprite; 
};
#endif
