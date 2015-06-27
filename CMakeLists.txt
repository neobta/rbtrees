cmake_minimum_required(VERSION 2.8)
project(redBlackTreesDemo)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(redBlackTreesDemo ${SOURCE_FILES} redBlackTreeItem.cpp redBlackTreeItem.hh)
