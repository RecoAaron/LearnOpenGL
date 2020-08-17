#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: SandEngine 核心头文件，定义常用宏。
*************************************************/

#ifdef SE_PLATFORM_WINDOWS /* Sand Engine 定义在 Windows 上 */
    #ifdef SE_BUILD_DLL                      /* 设置 DLL 项目 export 和 EXE 项目 import */
        #define SE_API __declspec(dllexport)
    #else
        #define SE_API __declspec(dllimport)
    #endif
#else
    #error Sand Engine is only for Windows!
#endif