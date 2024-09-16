cmake_minimum_required(VERSION 3.28)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project("Cirno")

add_subdirectory(engine)
add_subdirectory(sandbox)

add_subdirectory(vendor/glad-4.1)

add_subdirectory(vendor/glfw)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
if (MSVC)
    target_compile_options(glfw PRIVATE /wd4819)
endif()

add_subdirectory(vendor/spdlog)
if (MSVC)
    target_compile_options(spdlog PRIVATE /wd4819)
endif()