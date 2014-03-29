//ybzuo
#ifndef __SW_WORLD_H__
#define __SW_WORLD_H__
#include "cocos2d.h"
#include <vector>
class SwBase;
using namespace std;
class SwWorld{
 public:
  SwWorld(cocos2d::Layer* _layer);
  void init();
  void add_sprite(cocos2d::Sprite* _s);
 private:
  vector<SwBase*> m_sprite_list;
  cocos2d::Layer* m_layer;
};
#endif
