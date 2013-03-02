#include "engine/util/visiblerect.h"
#include "engine/mainscene.h"
#include "engine/controller.h"

MainScene::MainScene(bool bPortrait)
    :GameScene(bPortrait) {
}

void MainScene::onEnter() {
  GameScene::onEnter();
}

void MainScene::run() {
  CCDirector::sharedDirector()->replaceScene(this);
}
