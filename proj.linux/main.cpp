#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <cocos2d.h>
#include <CCEGLView.h>

#include <string>

#include "engine/appdelegate.h"

#include "proj.linux/main.h"

USING_NS_CC;

int main(int argc, char **argv) {
  // create the application instance
  AppDelegate app;
  CCEGLView* eglView = CCEGLView::sharedOpenGLView();
  eglView->setFrameSize(800, 480);
  return CCApplication::sharedApplication()->run();
}
