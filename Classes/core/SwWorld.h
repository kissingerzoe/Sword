//ybzuo
#ifndef __SW_WORLD_H__
#define __SW_WORLD_H__
#include "cocos2d.h"
#include <vector>
class SwBase;
class SwMap;
using namespace std;
class SwWorld{
 public:
  SwWorld(cocos2d::Layer* _layer);
  void init();
  void add_sprite(cocos2d::Sprite* _s);
  void update(float _delta);
  void on_key_pressed(cocos2d::EventKeyboard::KeyCode keyCode);
  void on_key_released(cocos2d::EventKeyboard::KeyCode keyCode);
 private:
  vector<SwBase*> m_sprite_list;
  SwBase* m_hero;
  cocos2d::Layer* m_layer;
  bool m_key_up=false;
  bool m_key_down=false;
  bool m_key_left=false;
  bool m_key_right=false;
  const float mc_speed=100.0f;
  SwMap* m_map;
};
#endif
