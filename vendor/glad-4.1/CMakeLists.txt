cmake_minimum_required(VERSION 3.16)

project(glad)
add_library(glad STATIC src/gl.c)
target_include_directories(glad PUBLIC include)