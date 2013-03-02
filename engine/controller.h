#ifndef ENGINE_CONTROLLER_H_
#define ENGINE_CONTROLLER_H_

#include <cocos2d.h>

USING_NS_CC;

class Controller : public CCLayer {
 public:
  Controller();
  ~Controller();

  void menuCallback(CCObject * pSender);
  void closeCallback(CCObject * pSender);

  virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
  virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);

 private:
  CCPoint m_tBeginPos;
  CCMenu* m_pItemMenu;
};

#endif
