#!/bin/bash -e

pushd proj.android
ant clean
rm -rf libs obj/local/armeabi/libengine.so obj/local/armeabi/objs/libengine_shared
popd
pushd proj.linux
make clean
rm -rf bin
popd
