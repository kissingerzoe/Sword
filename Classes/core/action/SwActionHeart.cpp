#include "SwActionHeart.h"
#include "SwAction.h"
void SwActionHeart::add(SwAction* _sa){
  for(int i=0;i<m_action_vec.size();++i){
    if(m_action_vec[i].get_name()==_sa.get_name()){return;}
  }
  m_action_vec.add(_sa);
}
void SwActionHeart::update(float _d){
  if(m_current_action!=NULL){
    m_current_action.update();
  }
}




