cmake_minimum_required(VERSION 3.20)

project(rendersphere)

include_directories(include)

set(SOURCE_FILES
    src/main.cpp
    src/renderer.cpp
)

add_executable(rendersphere ${SOURCE_FILES})