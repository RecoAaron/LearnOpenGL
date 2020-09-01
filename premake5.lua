workspace "SandEngine"  -- 设置工作空间名称
    architecture "x64"  -- 系统环境 x64
    startproject "Sandbox"

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

-- 包含解决方案的目录
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/SandEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/SandEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/SandEngine/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/SandEngine/vendor/glm"

group "Dependencies"
    include "vendor/premake"
    include "SandEngine/vendor/GLFW"
    include "SandEngine/vendor/Glad"
    include "SandEngine/vendor/imgui"

group ""

include "SandEngine"
include "Sandbox"