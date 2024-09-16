cmake_minimum_required(VERSION 3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(generated)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad-4.1)
add_subdirectory(vendor/spdlog)