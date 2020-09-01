project "SandEngine" -- 设置项目
    kind "StaticLib"  -- lib 输出
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")  -- target 目录
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}") -- obj 目录

    pchheader "sdpch.h"
    pchsource "src/sdpch.cpp"

    files
    {
        "src/**.h",  -- 包含所有 .h文件
        "src/**.cpp",  -- 包含所有 .cpp文件
        "vendor/glm/glm/**.hpp",
        "vendor/glm/glm/**.inl",
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "GLFW_INCLUDE_NONE"
    }

    includedirs
    {
        "src",
        "vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
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