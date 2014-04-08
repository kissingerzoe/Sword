#include "SwMap.h"
#include "SwMNode.h"
SwMap::SwMap(SwWorld* _world){
  m_world=_world;
  for(int i=0;i<10;++i){
    SwMNode* _n=new SwMNode(m_world);
    m_node_que.push(_n);
  }
}
void SwMap::next_wave(){
  m_node_que.front()->appear();
  m_node_que.pop();
}

