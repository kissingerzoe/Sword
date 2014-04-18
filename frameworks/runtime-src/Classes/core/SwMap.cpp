#include "SwMap.h"
#include "SwMNode.h"
SwMap::SwMap(SwWorld* _world){
  m_world=_world;
  for(int i=0;i<10;++i){
    SwMNode* _n=new SwMNode(m_world);
    m_node_que.push(_n);
  }
  next_wave();
}
void SwMap::next_wave(){
  m_current_node=m_node_que.front();
  m_node_que.pop();
}
void SwMap::update(float _detal){
  if(m_current_node!=NULL){
    if(m_current_node->update(_detal)){
      if(m_node_que.size()>0){
	next_wave();
      }else{
	m_current_node=NULL;
      }
    }
  }
}

