#include "SwMNode.h"
SwMNode:SwMNode(){
  for(int i=0;i<10;++i){
    SwSpriteConfig* _ssc =new SwSpriteConfig();
    m_sprite_list.push_back(_ssc);
  }
}
SwMNode:Apear(){
  for(int i=0;i<m_sprite_list.Count;++i){
    m_sprite_list[i].sprite=new SwBase();
  }
}
