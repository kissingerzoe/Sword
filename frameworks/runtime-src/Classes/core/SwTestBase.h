//ybzuo
#ifndef _SW_TEST_BASE_H
#define _SW_TEST_BASE_H
#include "cocos2d.h"
USING_NS_CC;
class SwBase;
class SwTestBase{
 public:
  SwTestBase(SwBase* _sb){
    m_sb=_sb;
  }
  void set_pos(Point _p);
  Point get_pos();
 private:
  SwBase* m_sb;
};
#endif
