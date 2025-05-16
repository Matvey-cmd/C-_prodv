cmake_minimum_required(VERSION 3.30)

set(PROJECT lib_example)
project(lib_example)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(les_1/shapelib)

add_executable(lib_example homework/Task1.cpp)
target_link_libraries(${PROJECT} PRIVATE shapelib)
