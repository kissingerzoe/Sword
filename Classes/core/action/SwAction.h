//ybzuo
#ifndef __SW_ACTION__
#define __SW_ACTION__
#include <string>
using namespace std;
class SwBase;
class SwAction{
 public:
  SwAction(SwBase* _b);
  virtual void update(float _d)=0;
  string get_name(){return "";}
 protected:  
  SwBase* m_owner;
};
#endif
