#ifndef ENGINE_GAMESCENE_H_
#define ENGINE_GAMESCENE_H_

#include <cocos2d.h>

USING_NS_CC;
class GameScene : public CCScene {
 public:
  explicit GameScene(bool bPortrait = false);

  virtual void onEnter();
  virtual void run() = 0;
  virtual void MainMenuCallback(CCObject* pSender);
};

#endif
