#include "SwMap.h"
#include "SwMNode.h"
SwMap::SwMap(){
  for(int i=0;i<10;++i){
    SwMNode* _n=new SwMNode();
    m_node_que.push(_n);
  }
}

