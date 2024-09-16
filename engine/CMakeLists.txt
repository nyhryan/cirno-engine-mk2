cmake_minimum_required(VERSION 3.28)

project("Cirno Engine")

set(TARGET_NAME "Cirno")
add_library(${TARGET_NAME} STATIC
    src/Logger.cpp
    src/Application.cpp
    src/Platforms/GL_Window.cpp
)

target_precompile_headers(${TARGET_NAME} PRIVATE
    include/Cirno_pch.hpp
)

target_compile_features(${TARGET_NAME} PUBLIC cxx_std_20)
if (MSVC)
    target_compile_options(${TARGET_NAME}
        PUBLIC /Zc:preprocessor
        PRIVATE /wd4819
    )
endif()

target_include_directories(${TARGET_NAME} PUBLIC include)
target_link_libraries(${TARGET_NAME} PUBLIC glfw glad spdlog)