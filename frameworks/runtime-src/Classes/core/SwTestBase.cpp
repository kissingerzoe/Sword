#include "SwTestBase.h"
#include "SwBase.h"
void SwTestBase::set_pos(Point _p){
  m_sb->set_pos(_p);
}
Point SwTestBase::get_pos(){
  return m_sb->get_pos();
}
