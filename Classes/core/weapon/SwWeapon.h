//ybzuo
class SwWorld;
class SwBase;
class SwWeapon{
 public:
  SwWeapon(SwWorld* _w,SwBase* _owner);
  void shot();
  void update(float);
 private:
  void real_shot();
  SwWorld* m_world;
  SwBase* m_owner;
  float m_interal=0.1f;
  float m_cd=0.0f;
  float m_speed=600.0f;
};

