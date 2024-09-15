require "vendor.premake-cmake-master.cmake"

function buildStatic(flag)
    if flag then
        defines {"CIRNO_EXPORTS"}
        kind "StaticLib"
    else
        kind "SharedLib"
        visibility "Hidden"
        defines { "CIRNO_EXPORTS", "CIRNO_SHARED" }
    end
end

workspace "Cirno Root"
    configurations { "Debug", "Release" }
    location "generated"

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

project "Cirno"
    language "C++"
    cppdialect "C++20"
    location "generated/engine"

    buildStatic(true)

    files { "engine/src/**.cpp", "engine/include/**.hpp" }
    includedirs { "engine/include" }

    links { "glfw", "glad" }

project "Sandbox"
    language "C++"
    cppdialect "C++20"

    location "generated/sandbox"
    kind "ConsoleApp"

    files { "sandbox/src/*.cpp" }
    includedirs { "engine/include" }
    links { "Cirno" }