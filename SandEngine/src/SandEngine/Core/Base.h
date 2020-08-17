#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: SandEngine 核心头文件，定义常用宏。
*************************************************/

#include <memory>

/* 平台预定义宏 */
#ifdef _WIN32
    /* Windows x64/x86 */
    #ifdef _WIN64
        /* Windows x64 */
        #define SE_PLATFORM_WINDOWS
        #ifdef SE_BUILD_DLL
            /* API dll export */
            #define SE_API __declspec(dllexport)
        #else
            /* API dll import */
            #define SE_API __declspec(dllimport)
        #endif
    #else
        /* Windows x86 */
        #error "x86 builds are not supported!"
    #endif
#else
    #error "SandEngine is only for Windows!"
#endif

/* 取位运算 */
#define SE_BIT(x) (1 << x)

namespace SE {

    template<typename T>
    using Ref = std::shared_ptr<T>;
}