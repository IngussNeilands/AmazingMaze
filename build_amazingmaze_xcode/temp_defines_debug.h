#ifndef I3D_OS_S3E
#   define I3D_OS_S3E 1
#endif
#ifndef I3D_PLATFORM_S3E
#   define I3D_PLATFORM_S3E 1
#endif
#ifndef IW_APP_NAME
#   define IW_APP_NAME "AmazingMaze"
#endif
#ifndef IW_APP_VERSION
#   define IW_APP_VERSION "1.0"
#endif
#ifndef IW_ASSERTION_CHANNEL_2D
#   define IW_ASSERTION_CHANNEL_2D 1
#endif
#ifndef IW_ASSERTION_CHANNEL_IW_2DSCENEGRAPH
#   define IW_ASSERTION_CHANNEL_IW_2DSCENEGRAPH 1
#endif
#ifndef IW_ASSERTION_CHANNEL_PVRTEXTOOL
#   define IW_ASSERTION_CHANNEL_PVRTEXTOOL 1
#endif
#ifndef IW_DEBUG
#   define IW_DEBUG 1
#endif
#ifndef IW_MKF_IW2D
#   define IW_MKF_IW2D 1
#endif
#ifndef IW_MKF_IW2DSCENEGRAPH
#   define IW_MKF_IW2DSCENEGRAPH 1
#endif
#ifndef IW_MKF_IW2DSCENEGRAPHCORE
#   define IW_MKF_IW2DSCENEGRAPHCORE 1
#endif
#ifndef IW_MKF_IWGEOM
#   define IW_MKF_IWGEOM 1
#endif
#ifndef IW_MKF_IWGL
#   define IW_MKF_IWGL 1
#endif
#ifndef IW_MKF_IWGX
#   define IW_MKF_IWGX 1
#endif
#ifndef IW_MKF_IWGXFONT
#   define IW_MKF_IWGXFONT 1
#endif
#ifndef IW_MKF_IWRESMANAGER
#   define IW_MKF_IWRESMANAGER 1
#endif
#ifndef IW_MKF_IWTWEEN
#   define IW_MKF_IWTWEEN 1
#endif
#ifndef IW_MKF_IWUTIL
#   define IW_MKF_IWUTIL 1
#endif
#ifndef IW_MKF_LIBJPEG
#   define IW_MKF_LIBJPEG 1
#endif
#ifndef IW_MKF_LIBPNG
#   define IW_MKF_LIBPNG 1
#endif
#ifndef IW_MKF_PVRTEXTOOL
#   define IW_MKF_PVRTEXTOOL 1
#endif
#ifndef IW_MKF_S3E_DEFAULT
#   define IW_MKF_S3E_DEFAULT 1
#endif
#ifndef IW_MKF_TINICONV
#   define IW_MKF_TINICONV 1
#endif
#ifndef IW_MKF_ZLIB
#   define IW_MKF_ZLIB 1
#endif
#ifndef IW_PLATFORM_S3E
#   define IW_PLATFORM_S3E 1
#endif
#ifndef IW_SDK
#   define IW_SDK 1
#endif
#ifndef IW_TRACE_CHANNEL_IW_2DSCENEGRAPH
#   define IW_TRACE_CHANNEL_IW_2DSCENEGRAPH 1
#endif
#ifndef IW_TRACE_CHANNEL_PVRTEXTOOL
#   define IW_TRACE_CHANNEL_PVRTEXTOOL 1
#endif
#ifndef IW_TRACE_CHANNEL_PVRTEXTOOL_VERBOSE
#   define IW_TRACE_CHANNEL_PVRTEXTOOL_VERBOSE 2
#endif
#ifndef IW_USE_ASSERTIONS
#   define IW_USE_ASSERTIONS 1
#endif
#ifndef IW_USE_CALLSTACK
#   define IW_USE_CALLSTACK 1
#endif
#ifndef IW_USE_TRACING
#   define IW_USE_TRACING 1
#endif
#ifndef S3E_INCLUDE_LEGACY
#   define S3E_INCLUDE_LEGACY 1
#endif
#ifndef __S3E__
#   define __S3E__ 1
#endif

/* including "extra_body" specified by the mkb plugin */

#if !defined I3D_ARCH_ARM && !defined I3D_ARCH_X86 && !defined I3D_ARCH_AARCH64
    #if defined __ARMCC_VERSION || defined __arm__
        #define I3D_ARCH_ARM
    #elif defined __aarch64__
        #define I3D_ARCH_AARCH64
    #else
        #define I3D_ARCH_X86
        #define I3D_ARCH_I386
    #endif
#endif

#if defined I3D_ARCH_ARM || defined I3D_ARCH_X86
    #if defined I3D_ARCH_64_BIT
        #error "Preprocessor macro mismatch.  Current architecture is not 64 Bit"
    #endif 
#else
    #ifdef I3D_ARCH_32_BIT
        #error "Preprocessor macro mismatch.  Current architecture is not 32 Bit"
    #endif
#endif   

#if defined I3D_ARCH_X86 && !defined __i386__
    #define __i386__
#endif

#if defined I3D_ARCH_ARM && !defined __ARM__
    #define __ARM__
#endif
#if !defined I3D_ARCH_32_BIT && !defined I3D_ARCH_64_BIT
    #if defined I3D_ARCH_AARCH64 || defined I3D_ARCH_AMD64
        #define I3D_ARCH_64_BIT
    #else
        #define I3D_ARCH_32_BIT
    #endif
#endif
