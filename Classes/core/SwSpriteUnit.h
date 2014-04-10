//ybzuo
#ifndef __SW_SPRITE_UNIT__
#define __SW_SPRITE_UNIT__
#include "cocos2d.h"
class SwBase;
class SwWorld;
class SwSpriteUnit{
 public:
  SwSpriteUnit(SwWorld* _w);
  bool update(float _d);
 private:
  void appear();
  float begin_time; 
  cocos2d::Point begin_pos;
  cocos2d::Point work_pos;
  SwBase* sprite;
  SwWorld* m_world;
}; 
#endif
