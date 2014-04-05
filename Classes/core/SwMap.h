//ybzuo
#ifndef __SW_MAP_H__
#define __SW_MAP_H__
#include <queue>
class SwMNode;
using namespace std;
class SwMap{
 public:
  SwMap();
 private:
  queue<SwMNode*> m_node_que;
};


#endif
