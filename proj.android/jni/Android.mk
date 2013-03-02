LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libengine_shared

LOCAL_MODULE_FILENAME := libengine

LOCAL_SRC_FILES := libengine/main.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../..

LOCAL_WHOLE_STATIC_LIBRARIES := cocos_engine_common
LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-add-path, $(LOCAL_PATH)/../..)
$(call import-module, .)
$(call import-module, cocos2dx)
$(call import-module, cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module, CocosDenshion/android)
$(call import-module, extensions)
$(call import-module, external/Box2D)
$(call import-module, external/chipmunk)
