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
  void lua_bind();
  void add_sprite(SwBase* _sb);
  void remove_sprite(SwBase* _sb);
  void update(float _delta);
  void on_key_pressed(cocos2d::EventKeyboard::KeyCode keyCode);
  void on_key_released(cocos2d::EventKeyboard::KeyCode keyCode);
  void shot();
  inline cocos2d::Point fix_pos(cocos2d::Point _p){return _p+m_half_size;}
 private:
  vector<SwBase*> m_sprite_list;
  vector<int> m_remove_list;
  vector<SwBase*> m_add_list;
  SwBase* m_hero;
  cocos2d::Layer* m_layer;
  bool m_key_up=false;
  bool m_key_down=false;
  bool m_key_left=false;
  bool m_key_right=false;
  bool m_key_shot=false;
  const float mc_speed=200.0f;
  SwMap* m_map;
  cocos2d::Size m_size;
  cocos2d::Point m_origin;
  cocos2d::Point m_half_size;
};
#endif
