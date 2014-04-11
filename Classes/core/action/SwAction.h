//ybzuo
#ifndef __SW_ACTION__
#define __SW_ACTION__
class SwBase;
class SwAction{
 public:
  SwAction(SwBase* _b);
  vitrual void update(float _d)=0;
 protected:  
  SwBase* m_owner;
}
#endif
