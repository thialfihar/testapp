LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos_engine_common

LOCAL_MODULE_FILENAME := libenginecommon

FILE_LIST := $(wildcard $(LOCAL_PATH)/engine/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/engine/util/*.cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)

include $(BUILD_STATIC_LIBRARY)

$(call import-module,CocosDenshion/android)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
$(call import-module,cocos2dx)
$(call import-module,extensions)
