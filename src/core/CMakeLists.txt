cmake_minimum_required(VERSION 4.0)

project(graviton_core)

file(GLOB_RECURSE SRC_FILES *.cpp)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES})
