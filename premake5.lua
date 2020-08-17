workspace "SandEngine"  -- 设置工作空间名称
    architecture "x64"  -- 系统环境 x64

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" -- 输出目录  Debug-Windows-x64

-- 包含解决方案的目录
IncludeDir = {}

startproject "Sandbox"

project "SandEngine" -- 设置项目
    location "SandEngine"
    kind "SharedLib"  -- dll 输出
    language "C++"

    targetdir("bin/" .. outputDir .. "/%{prj.name}")  -- target 目录
    objdir("bin-int/" .. outputDir .. "/%{prj.name}") -- obj 目录

    pchheader "sdpch.h"
    pchsource "SandEngine/src/sdpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",  -- 包含所有 .h文件
        "%{prj.name}/src/**.cpp"  -- 包含所有 .cpp文件
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On" -- 链接动态库
        systemversion "latest"

        defines
        {
            "SE_PLATFORM_WINDOWS",
            "SE_BUILD_DLL",
        }

        -- 编译完成后自动将 .dll 放置到 .exe 同目录
        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputDir.. "/Sandbox")
        }

        filter "configurations:Debug" -- 只定义在 Debug 模式下
            defines "SE_DEGUG"
            symbols "On"

        filter "configurations:Release" --只定义在 Release 模式下
            defines "SE_RELEASE"
            optimize "On"

        filter "configurations:Dist" --只定义在 Dist 模式下
            defines "SE_DIST"
            optimize "On"

project "Sandbox" -- 设置项目
    location "Sandbox"
    kind "ConsoleApp"  -- exe 输出
    language "C++"
        
    targetdir("bin/" .. outputDir .. "/%{prj.name}")  -- target 目录
    objdir("bin-int/" .. outputDir .. "/%{prj.name}") -- obj 目录
        
    files
    {
        "%{prj.name}/src/**.h",  -- 包含所有 .h文件
        "%{prj.name}/src/**.cpp"  -- 包含所有 .cpp文件
    }

    includedirs
    {
        "SandEngine/vendor/spdlog/include",
        "SandEngine/src"
    }

    links
    {
        "SandEngine", -- 链接 SandEngine.dll
    }
        
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On" -- 链接动态库
        systemversion "latest"
        
        defines
        {
            "SE_PLATFORM_WINDOWS"
        }
        
        filter "configurations:Debug" -- 只定义在 Debug 模式下
            defines "SE_DEGUG"
            symbols "On"
        
        filter "configurations:Release" --只定义在 Release 模式下
            defines "SE_RELEASE"
            optimize "On"
        
        filter "configurations:Dist" --只定义在 Dist 模式下
            defines "SE_DIST"
            optimize "On"