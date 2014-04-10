//ybzuo
#ifndef __SW_MAP_H__
#define __SW_MAP_H__
#include <queue>
class SwMNode;
class SwWorld;
using namespace std;
class SwMap{
 public:
  SwMap(SwWorld* _sw);
  void update(float _detail);
  void next_wave();
 private:
  queue<SwMNode*> m_node_que;
  SwMNode* m_current_node=NULL;
  SwWorld* m_world;
};
#endif
