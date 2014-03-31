//ybzuo
#include "ScRoot.h"
#include "SwWorld.h"
USING_NS_CC;

Scene* ScRoot::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ScRoot::create();

    // add lxfayer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ScRoot::init()
{
  //////////////////////////////
  // 1. super init first
  if ( !Layer::init() )
    {
      return false;
    }
    
  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();

  /////////////////////////////
  // 2. add a menu item with "X" image, which is clicked to quit the program
  //    you may modify it.

  // add a "close" icon to exit the progress. it's an autorelease object
  auto closeItem = MenuItemImage::create(
					 "CloseNormal.png",
					 "CloseSelected.png",
					 CC_CALLBACK_1(ScRoot::menuCloseCallback, this));
    
  closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
			       origin.y + closeItem->getContentSize().height/2));

  // create menu, it's an autorelease object
  auto menu = Menu::create(closeItem, NULL);
  menu->setPosition(Point::ZERO);
  this->addChild(menu, 1);

  /////////////////////////////
  // 3. add your codes below...

  // add a label shows "Hello World"
  // create and initialize a label
    
  //  auto label = LabelTTF::create("Hello World", "Arial", 24);
    
  // position the label on the center of the screen
  // label->setPosition(Point(origin.x + visibleSize.width/2,
  //			   origin.y + visibleSize.height - label->getContentSize().height));

  // add the label as a child to this layer
// this->addChild(label, 1);

  /*
  // add "ScRoot" splash screen"
  Sprite* sprite = Sprite::create("hero.png");

  // position the sprite on the center of the screen
  sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

  // add the sprite as a child to this layer
  this->addChild(sprite, 0);
  */
  auto listener = EventListenerKeyboard::create();
  listener->onKeyPressed = CC_CALLBACK_2(ScRoot::onKeyPressed, this);
  listener->onKeyReleased = CC_CALLBACK_2(ScRoot::onKeyReleased, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
  m_world=new SwWorld(this);
  m_world->init();
  
  scheduleUpdate();

  return true;
}
void ScRoot::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void ScRoot::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
  m_world->on_key_pressed(keyCode);
  // log("Key with keycode %d pressed", keyCode);
}

void ScRoot::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
  m_world->on_key_released(keyCode);
  //log("Key with keycode %d released", keyCode);
}

void ScRoot::update(float _d){
  m_world->update(_d);
}

