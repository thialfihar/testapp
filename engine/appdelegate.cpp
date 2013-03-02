#include <cocos2d.h>
#include <SimpleAudioEngine.h>

#include <string>
#include <vector>

#include "engine/appdelegate.h"
#include "engine/controller.h"

USING_NS_CC;

AppDelegate::AppDelegate() {
}

AppDelegate::~AppDelegate() {
}

bool AppDelegate::applicationDidFinishLaunching() {
  // initialize director
  CCDirector *pDirector = CCDirector::sharedDirector();
  pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

  CCSize screenSize = CCEGLView::sharedOpenGLView()->getFrameSize();

  CCSize designSize = CCSizeMake(480, 320);
  CCFileUtils* pFileUtils = CCFileUtils::sharedFileUtils();

  if (screenSize.height > 320) {
    CCSize resourceSize = CCSizeMake(960, 640);
    std::vector<std::string> searchPaths;
    searchPaths.push_back("hd");
    pFileUtils->setSearchPaths(searchPaths);
    pDirector->setContentScaleFactor(resourceSize.height/designSize.height);
  }

  CCEGLView::sharedOpenGLView()
      ->setDesignResolutionSize(designSize.width, designSize.height,
                                kResolutionNoBorder);

  // turn on display FPS
  pDirector->setDisplayStats(true);

  // set FPS. the default value is 1.0/60 if you don't call this
  pDirector->setAnimationInterval(1.0 / 60);

  CCScene * pScene = CCScene::create();
  CCLayer * pLayer = new Controller();
  pLayer->autorelease();

  pScene->addChild(pLayer);
  pDirector->runWithScene(pScene);

  return true;
}

// This function will be called when the app is inactive.
void AppDelegate::applicationDidEnterBackground() {
  CCDirector::sharedDirector()->stopAnimation();
  CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
  CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// This function will be called when the app is active again.
void AppDelegate::applicationWillEnterForeground() {
  CCDirector::sharedDirector()->startAnimation();
  CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
  CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
