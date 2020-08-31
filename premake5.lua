workspace "SandEngine"  -- 设置工作空间名称
    architecture "x64"  -- 系统环境 x64

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    flags
    {
        "MultiProcessorCompile" -- 多线程
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" -- 输出目录  Debug-Windows-x64

startproject "Sandbox"

-- 包含解决方案的目录
IncludeDir = {}
IncludeDir["GLFW"] = "SandEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "SandEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "SandEngine/vendor/imgui"

group "Dependencies"
    include "SandEngine/vendor/GLFW"
    include "SandEngine/vendor/Glad"
    include "SandEngine/vendor/imgui"

group ""

project "SandEngine" -- 设置项目
    location "SandEngine"
    kind "StaticLib"  -- lib 输出
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")  -- target 目录
    objdir("bin-int/" .. outputdir .. "/%{prj.name}") -- obj 目录

    pchheader "sdpch.h"
    pchsource "SandEngine/src/sdpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",  -- 包含所有 .h文件
        "%{prj.name}/src/**.cpp"  -- 包含所有 .cpp文件
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "GLFW_INCLUDE_NONE"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {

        }

        filter "configurations:Debug" -- 只定义在 Debug 模式下
            defines "SE_DEBUG"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release" --只定义在 Release 模式下
            defines "SE_RELEASE"
            runtime "Release"
            optimize "on"

        filter "configurations:Dist" --只定义在 Dist 模式下
            defines "SE_DIST"
            runtime "Release"
            optimize "on"

project "Sandbox" -- 设置项目
    location "Sandbox"
    kind "ConsoleApp"  -- exe 输出
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
        
    targetdir("bin/" .. outputdir .. "/%{prj.name}")  -- target 目录
    objdir("bin-int/" .. outputdir .. "/%{prj.name}") -- obj 目录
        
    files
    {
        "%{prj.name}/src/**.h",  -- 包含所有 .h文件
        "%{prj.name}/src/**.cpp"  -- 包含所有 .cpp文件
    }

    includedirs
    {
        "SandEngine/vendor/spdlog/include",
        "SandEngine/src",
        "SandEngine/vendor"
    }

    links
    {
        "SandEngine", -- 链接 SandEngine.dll
    }
        
    filter "system:windows"
        systemversion "latest"
        
        defines
        {
            "SE_PLATFORM_WINDOWS"
        }
        
        filter "configurations:Debug" -- 只定义在 Debug 模式下
            defines "SE_DEBUG"
            runtime "Debug"
            symbols "On"
        
        filter "configurations:Release" --只定义在 Release 模式下
            defines "SE_RELEASE"
            runtime "Release"
            optimize "On"
        
        filter "configurations:Dist" --只定义在 Dist 模式下
            defines "SE_DIST"
            runtime "Release"
            optimize "On"