#include "SwMNode.h"
#include <cstdlib>
#include "SwBase.h"
#include "SwWorld.h"
#include "SwSpriteUnit.h"
USING_NS_CC;
SwMNode::SwMNode(SwWorld* _sw){
  m_world=_sw;
  m_time=rand()%3+1;
  for(int i=0;i<5;++i){
    SwSpriteUnit* _ssc =new SwSpriteUnit(_sw);
    m_sprite_list.push_back(_ssc);
  }
 }
/*
void SwMNode::appear(){
  for(int i=0;i<m_sprite_list.size();++i){
  }
}
*/
bool SwMNode::update(float _detal){
  if(m_time>0.0f){
    m_time-=_detal;
    if(m_time<=0.0f){
      m_time=-1.0f;
    }
    return false;
  }else{
    bool _finish=true;
    for(int i=0;i<m_sprite_list.size();++i){
      if(!m_sprite_list[i]->update(_detal)){_finish=false;}
    }
    return _finish;
  }
}
