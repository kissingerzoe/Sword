//ybzuo
#ifndef __SW_ACTION_HEART__
#define __SW_ACTION_HEART__
#inlcude <vector>
class SwAction;
class SwActionHeart{
 public:
  // void 
  void add(string,SwAction*);
  void update(float _d);
 private:
  vector<SwAction*> m_action_vec;
  SwAction* m_current_action;
}
