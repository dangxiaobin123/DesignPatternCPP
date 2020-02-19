cmake_minimum_required(VERSION 3.2)

project(DesignPattern CXX)

#use c++11
if(CMAKE_VERSION VERSION_LESS 3)
    add_definitions(-std=c++14)
else()
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(NOT PROJECT_BINARY_DIR)
    set(PROJECT_BINARY_DIR build)
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/run)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(thirdparty/catch2)
add_subdirectory(thirdparty/nanolog)
add_subdirectory(src/Pattern)
add_subdirectory(src/ModernCpp)
