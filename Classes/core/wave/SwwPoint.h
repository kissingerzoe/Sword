//ybzuo
//wave
#ifndef __SWW_POINT_H__
#define __SWW_POINT_H__
#include "SwBase.h"
#include <vector>
class SwwPoint:public SwBase{
 public:
  SwwPoint(SwWorld* _sw,SwBase* _owner,cocos2d::Point _speed);
  void update(float _d);
  void collide_update(SwBase* _sb);
 private:
  cocos2d::Point m_speed;
  int m_damage=1;
  SwBase* m_owner;
  float m_life_time=10.0f;
};
#endif
