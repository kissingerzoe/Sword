#include "SwMNode.h"
#include <cstdlib>
#include "SwBase.h"
#include "SwWorld.h"
USING_NS_CC;
SwMNode::SwMNode(SwWorld* _sw){
  m_world=_sw;
  for(int i=0;i<10;++i){
    SwSpriteConfig* _ssc =new SwSpriteConfig();
    m_sprite_list.push_back(_ssc);
  }
}
void SwMNode::appear(){
  for(int i=0;i<m_sprite_list.size();++i){
    m_sprite_list[i]->sprite=new SwBase(m_world);
    m_sprite_list[i]->sprite->set_pos(Point(100+rand()%100,200+rand()%300));
  }
}
