#ifndef ENGINE_UTIL_VISIBLERECT_H_
#define ENGINE_UTIL_VISIBLERECT_H_

#include <cocos2d.h>

USING_NS_CC;

class VisibleRect {
 public:
  static CCRect getVisibleRect();
  static CCPoint left();
  static CCPoint right();
  static CCPoint top();
  static CCPoint bottom();
  static CCPoint center();
  static CCPoint leftTop();
  static CCPoint rightTop();
  static CCPoint leftBottom();
  static CCPoint rightBottom();

 private:
  static void lazyInit();
  static CCRect s_visibleRect;
};

#endif
