cmake_minimum_required(VERSION 3.28)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project("Cirno Engine")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(IMGUI_DIR vendor/imgui)

set(IMGUI_SOURCE
    ${IMGUI_DIR}/imconfig.h
    ${IMGUI_DIR}/imgui.h
    ${IMGUI_DIR}/imgui_internal.h
    ${IMGUI_DIR}/imstb_rectpack.h
    ${IMGUI_DIR}/imstb_textedit.h
    ${IMGUI_DIR}/imstb_truetype.h
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.h
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.h
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

set(TARGET_NAME "Cirno")
add_library(${TARGET_NAME} STATIC
    src/Logger.cpp
    src/LayerStack.cpp
    src/Application.cpp
    src/Platforms/GL_Window.cpp
    src/Imgui/ImguiLayer.cpp
    ${IMGUI_SOURCE}
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

target_include_directories(${TARGET_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        vendor/glad-4.1/include
        vendor/glfw/include
        vendor/spdlog/include
        vendor/imgui
)
target_link_libraries(${TARGET_NAME} PUBLIC glfw glad spdlog)