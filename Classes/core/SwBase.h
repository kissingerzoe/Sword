//ybzuo
//base
#ifndef __SW_BASE_H__
#define __SW_BASE_H__
#include "cocos2d.h"
#include "SwWorld.h"
#include "Box2D/Box2D.h"
class SwBase{
 public:
  SwBase(SwWorld* _sw);
  ~SwBase();
  void set_pos(cocos2d::Point _pos);
  void set_rotate(float _rot);
  void hurt(int _damage);
  inline int get_life()const{return m_life;}
  inline cocos2d::Point get_pos(){return m_pos;}
  inline b2PolygonShape* get_b2poly(){return m_shape;}
  inline cocos2d::Sprite* get_coco_sprite(){return m_sprite;}
 private:
  SwWorld* m_world;
  cocos2d::Point m_pos;
  cocos2d::Sprite* m_sprite;
  float m_rotate;
  b2PolygonShape* m_shape;
  cocos2d::Rect m_tex_rect;
  int m_life=3;
};
#endif
