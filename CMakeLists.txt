cmake_minimum_required(VERSION 3.28)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project("Cirno")

add_subdirectory(engine)

add_subdirectory(engine/vendor/glad-4.1)

add_subdirectory(engine/vendor/glfw)
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

if (MSVC)
target_compile_options(glfw PRIVATE /wd4819)
endif()

add_subdirectory(engine/vendor/spdlog)
if (MSVC)
target_compile_options(spdlog PRIVATE /wd4819)
endif()

add_subdirectory(sandbox)