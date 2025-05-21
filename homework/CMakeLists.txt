cmake_minimum_required(VERSION 3.30)

SET(CMAKE_CXX_STANDARD 20)

project(homework)

add_executable(Task1
        ${CMAKE_CURRENT_SOURCE_DIR}/Task1/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Task1/Task1.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Task1/Task1.h
)

add_executable(Task2
        ${CMAKE_CURRENT_SOURCE_DIR}/Task2/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Task2/Task2.h
)

add_executable(Task3
        ${CMAKE_CURRENT_SOURCE_DIR}/Task3/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Task3/Task3.h
)

add_executable(Task4
        ${CMAKE_CURRENT_SOURCE_DIR}/Task4/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Task4/Task4.h
)

add_executable(Task5
        ${CMAKE_CURRENT_SOURCE_DIR}/Task5/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Task5/Logger.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Task5/Logger.h
)

add_executable(Task6
        ${CMAKE_CURRENT_SOURCE_DIR}/Task6/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Task6/CheckPoint.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Task6/CheckPoint.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Task6/CheckpointBuilder.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Task6/CheckpointBuilder.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Task6/Director.h
)

add_executable(Task7
        ${CMAKE_CURRENT_SOURCE_DIR}/Task7/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Task7/Set.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Task7/Set.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Task7/SetImpl.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Task7/UnorderedImpl.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Task7/UnorderedImpl.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Task7/VectorImpl.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Task7/VectorImpl.h
)
