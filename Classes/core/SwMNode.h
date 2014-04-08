//ybzuo
#ifndef __SW_MNODE__
#define __SW_MNODE__
#include<vector>
using namespace std;
class SwBase;
class SwWorld;
class SwSpriteConfig{
 public:
  float begin_time; 
  SwBase* sprite;
}; 
class SwMNode{
 public:
  SwMNode(SwWorld* _sw);
  void appear();
 private:
  vector<SwSpriteConfig*> m_sprite_list;
  SwWorld* m_world;
};
#endif
