#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: 预编译头文件
*************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include <fstream>

#include "SandEngine/Core/Log.h"

#include "SandEngine/Debug/Instrumentor.h"

#ifdef SE_PLATFORM_WINDOWS
    #include <Windows.h>
#endif