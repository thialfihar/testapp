CC      = gcc
CXX     = g++
TARGET	= engine
CCFLAGS = -Wall
CXXFLAGS = -Wall
VISIBILITY =
LIBS =

COCOS2DX_PATH = $(COCOS2DX_ROOT)/cocos2dx
THIS_MAKEFILE_PATH = $(realpath $(dir $(firstword $(MAKEFILE_LIST))))
PROJECT_ROOT = $(shell cd $(dir $(THIS_MAKEFILE_PATH));pwd)
INCLUDES =  -I$(PROJECT_ROOT) \
			-I$(COCOS2DX_PATH) \
			-I$(COCOS2DX_PATH)/platform/third_party/linux/libfreetype2 \
			-I$(COCOS2DX_PATH)/cocoa \
			-I$(COCOS2DX_PATH)/include \
			-I$(COCOS2DX_PATH)/kazmath/include \
			-I$(COCOS2DX_PATH)/platform \
			-I$(COCOS2DX_PATH)/platform/linux \
			-I$(COCOS2DX_PATH)/platform/third_party/linux/libxml2 \
			-I$(COCOS2DX_PATH)/platform/third_party/linux/libjpeg  \
			-I$(COCOS2DX_ROOT)/CocosDenshion/include \
			-I$(COCOS2DX_ROOT)/extensions/ \
			-I$(COCOS2DX_ROOT)/external/ \
			-I$(COCOS2DX_ROOT)/external/chipmunk/include/chipmunk

LBITS := $(shell getconf LONG_BIT)
ifeq ($(LBITS),64)
INCLUDES += -I$(COCOS2DX_PATH)/platform/third_party/linux/include64
else
INCLUDES += -I$(COCOS2DX_PATH)/platform/third_party/linux
endif

DEFINES = -DLINUX

CPP_FILES := $(wildcard $(PROJECT_ROOT)/engine/*.cpp)
CPP_FILES += $(wildcard $(PROJECT_ROOT)/engine/util/*.cpp)
CPP_FILES += $(wildcard $(PROJECT_ROOT)/proj.linux/*.cpp)
LOCAL_OBJECTS := $(CPP_FILES:.cpp=.o)
OBJECTS := $(LOCAL_OBJECTS)

include $(COCOS2DX_ROOT)/extensions/proj.linux/Makefile
OBJECTS += $(addprefix $(COCOS2DX_ROOT)/extensions/proj.linux/, $(EXTENSIONS_OBJECTS))

ifeq ($(LBITS),64)
STATICLIBS_DIR = $(COCOS2DX_PATH)/platform/third_party/linux/libraries/lib64
else
STATICLIBS_DIR = $(COCOS2DX_PATH)/platform/third_party/linux/libraries
endif
STATICLIBS = $(STATICLIBS_DIR)/libfreetype.a \
				$(STATICLIBS_DIR)/libcurl.a \
				$(STATICLIBS_DIR)/libxml2.a \
				$(STATICLIBS_DIR)/libpng.a \
				$(STATICLIBS_DIR)/libjpeg.a \
				$(STATICLIBS_DIR)/libtiff.a \
				$(COCOS2DX_ROOT)/lib/linux/Debug/libbox2d.a \
				$(COCOS2DX_ROOT)/lib/linux/Debug/libchipmunk.a \

SHAREDLIBS =
ifeq ($(LBITS),64)
SHAREDLIBS_DIR = $(COCOS2DX_ROOT)/CocosDenshion/third_party/fmod/lib64/api/lib
SHAREDLIBS = -L$(SHAREDLIBS_DIR) -lfmodex64
else
SHAREDLIBS_DIR = $(COCOS2DX_ROOT)/CocosDenshion/third_party/fmod/api/lib
SHAREDLIBS = -L$(SHAREDLIBS_DIR) -lfmodex
endif

SHAREDLIBS += -lglfw
SHAREDLIBS += -Wl,-rpath,$(SHAREDLIBS_DIR)
SHAREDLIBS += -L$(COCOS2DX_PATH)/platform/third_party/linux/glew-1.7.0/glew-1.7.0/lib -lGLEW
SHAREDLIBS += -Wl,-rpath,$(COCOS2DX_PATH)/platform/third_party/linux/glew-1.7.0/glew-1.7.0/lib


SHAREDLIBS += -Wl,-rpath,$(STATICLIBS_DIR)
SHAREDLIBS += -lcurl

BIN_DIR_ROOT=$(PROJECT_ROOT)/proj.linux/bin
BIN_DIR = BIN_DIR_ROOT

debug: SHAREDLIBS += -L$(COCOS2DX_ROOT)/lib/linux/Debug -lcocos2d -lrt -lz -lcocosdenshion -Wl,-rpath,$(COCOS2DX_ROOT)/lib/linux/Debug
debug: CCFLAGS += -g3 -O0
debug: CXXFLAGS += -g3 -O0
debug: DEFINES += -DDEBUG -DCC_ENABLE_CHIPMUNK_INTEGRATION -DCOCOS2D_DEBUG=1
debug: BIN_DIR = $(BIN_DIR_ROOT)/debug
debug: $(TARGET)

release: SHAREDLIBS += -L$(COCOS2DX_ROOT)/lib/linux/Release -lcocos2d -lrt -lz -lcocosdenshion -Wl,-rpath,$(COCOS2DX_ROOT)/lib/linux/Release
release: CCFLAGS += -O3
release: CXXFLAGS += -O3
release: DEFINES += -DNDEBUG -DCC_ENABLE_CHIPMUNK_INTEGRATION -DCC_ENABLE_BOX2D_INTEGRATION
release: BIN_DIR = $(BIN_DIR_ROOT)/release
release: $(TARGET)

####### Build rules
$(TARGET): $(OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(OBJECTS) -o $(BIN_DIR)/$(TARGET) $(SHAREDLIBS) $(STATICLIBS) $(LIBS)


####### Compile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

clean:
	rm -f $(LOCAL_OBJECTS) $(TARGET) core

clean_all:
	rm -f $(OBJECTS) $(TARGET) core