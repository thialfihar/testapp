#include "engine/util/visiblerect.h"
#include "engine/gamescene.h"
#include "engine/controller.h"

GameScene::GameScene(bool bPortrait) {
  CCScene::init();
}

void GameScene::onEnter() {
  CCScene::onEnter();

  CCLabelTTF* label = CCLabelTTF::create("MainMenu", "Arial", 15);
  CCMenuItemLabel* pMenuItem =
    CCMenuItemLabel::create(label, this,
                            menu_selector(GameScene::MainMenuCallback));

  CCMenu* pMenu =CCMenu::create(pMenuItem, NULL);

  pMenu->setPosition(CCPointZero);
  pMenuItem->setPosition(ccp(VisibleRect::right().x - 50,
                             VisibleRect::bottom().y + 25));

  addChild(pMenu, 1);
}

void GameScene::MainMenuCallback(CCObject* pSender) {
  CCScene* pScene = CCScene::create();
  CCLayer* pLayer = new Controller();
  pLayer->autorelease();

  pScene->addChild(pLayer);
  CCDirector::sharedDirector()->replaceScene(pScene);
}
