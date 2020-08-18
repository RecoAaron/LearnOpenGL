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

/* debug 模式下启用 assert */
#ifdef SE_DEBUG
    /* Debug 模式下 */
    #if defined(SE_PLATFORM_WINDOWS)
        /* Windows 平台上 */
        #define SE_DEBUGBREAK() __debugbreak()
    #else
        /* 其他平台暂不支持 */
        #error "Platform doesn't support debugbreak yet!"
    #endif
    /* 启用 assert */
    #define SE_ENABLE_ASSERTS
#else
    /* 其他模式下不启用 assert */
    #define SE_DEBUGBREAK()
#endif

#ifdef SE_ENABLE_ASSERTS
    /* 如果启用 assert 不满足条件程序会出现 break */
    #define SE_ASSERT(x, ...) { if(!(x)) { SE_LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); SE_DEBUGBREAK(); } }
    #define SE_CORE_ASSERT(x, ...) { if(!(x)) { SE_LOG_ERROR_CORE("Assertion Failed: {0}", __VA_ARGS__); SE_DEBUGBREAK(); } }
#else
    /* 不启用 assert 则忽略 */
    #define HZ_ASSERT(x, ...)
    #define HZ_CORE_ASSERT(x, ...)
#endif

/* 取位运算 */
#define SE_BIT(x) (1 << x)

/* 事件绑定宏 */
#define SE_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace SE {

    template<typename T>
    using Scope = std::unique_ptr<T>;

    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;
}