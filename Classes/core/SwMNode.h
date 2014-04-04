//ybzuo
#ifndef __SW_MNODE__
#define __SW_MNODE__
#include<vector>
using namespace std;
class SwBase;
class SwSpriteConfig{
 public:
  float begin_time; 
  SwBase* sprite;
}
class SwMNode{
 public:
  SwMNode(){
    for(int i=0;i<10;++i){
      SwSpriteConfig* _ssc =new SwSpriteConfig();
      m_sprite_list.PushBack(_ssc);
    }
  }
 private:
  vector<SwSpriteConfig*> m_sprite_list;
}
#endif
