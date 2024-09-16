cmake_minimum_required(VERSION 3.28)

project("Sandbox")

set(TARGET_NAME "Sandbox")
add_executable(${TARGET_NAME} src/Sandbox.cpp)
target_link_libraries(${TARGET_NAME} PRIVATE Cirno)