//ybzuo
#ifndef __SW_MNODE__
#define __SW_MNODE__
#include<vector>
using namespace std;
class SwBase;
class SwWorld;
class SwSpriteUnit;
class SwMNode{
 public:
  SwMNode(SwWorld* _sw);
  // void appear();
  bool update(float _detal);
 private:
  vector<SwSpriteUnit*> m_sprite_list;
  SwWorld* m_world;
  float m_time;
};
#endif
