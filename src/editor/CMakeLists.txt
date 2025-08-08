cmake_minimum_required(VERSION 4.0)

project(graviton_editor)

file(GLOB_RECURSE SRC_FILES *.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES}
        ../core/util/String.h
        ../core/util/String.cpp)
