#ifndef ENGINE_MAINSCENE_H_
#define ENGINE_MAINSCENE_H_

#include <cocos2d.h>

#include "engine/gamescene.h"

USING_NS_CC;

class MainScene : public GameScene {
 public:
  explicit MainScene(bool bPortrait = false);

  virtual void onEnter();
  virtual void run();
};

#endif
