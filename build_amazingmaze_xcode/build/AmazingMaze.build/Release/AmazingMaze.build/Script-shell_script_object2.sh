#!/bin/bash
set -e
if [ "$CONFIGURATION" = "Debug" -o "$CONFIGURATION" = "Debug ARM" -o "$CONFIGURATION" = "Debug AARCH64" ]; then echo "skipping for debug builds" && exit 0; fi
if [ "$CONFIGURATION" = "Debug ARM" -o "$CONFIGURATION" = "Release ARM" -o "$CONFIGURATION" = "Debug AARCH64" -o "$CONFIGURATION" = "Release AARCH64" ]; then echo "skipping for arm and aarch64 builds" && exit 0; fi
export GCC_THUMB_SUPPORT='NO'
PATH="/Applications/Marmalade.app/Contents/tools/gcc/x86/android_osx/bin":$PATH
PATH="/Applications/Marmalade.app/Contents/s3e/bin":$PATH
PATH="/Applications/Marmalade.app/Contents/s3e/gcc/darwin/aarch64/bin":$PATH
PATH="/Applications/Marmalade.app/Contents/s3e/gcc/darwin/arm/bin":$PATH
PATH="/usr/bin":$PATH
PATH="/Applications/Xcode.app/Contents/Developer/usr/bin":$PATH
PATH="/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin":$PATH
PATH="/opt/local/bin":$PATH
cd "/Applications/Marmalade.app/Contents/s3e/loader/osx"
/usr/bin/python ./postlink.py "${TARGET_BUILD_DIR}/${EXECUTABLE_NAME}" "/Users/xiaolilillytang/Desktop/AmazingMaze/build_amazingmaze_xcode/build/${CONFIGURATION}${EFFECTIVE_PLATFORM_NAME}/AmazingMaze.s86"
