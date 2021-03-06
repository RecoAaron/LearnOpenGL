project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "%{wks.location}/SandEngine/vendor/spdlog/include",
        "%{wks.location}/SandEngine/src",
        "%{wks.location}/SandEngine/vendor",
        "%{IncludeDir.glm}",
    }

    links
    {
        "SandEngine"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines "SE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "SE_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "SE_DIST"
        runtime "Release"
        optimize "on"
