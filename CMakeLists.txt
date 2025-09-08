cmake_minimum_required(VERSION 3.20)

project(rendersphere)

include_directories(include)

set(SOURCE_FILES
    src/main.cpp
    src/renderer.cpp
    src/scene.cpp
)

add_executable(rendersphere ${SOURCE_FILES})

add_executable(simple_test tests/simple_test.cpp src/renderer.cpp src/scene.cpp)

enable_testing()
add_test(NAME simple_test COMMAND simple_test)