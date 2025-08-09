cmake_minimum_required(VERSION 4.0)

project(graviton_core)

add_library(${PROJECT_NAME} STATIC
    Engine.cpp
    Engine.h

    util/String.h
    util/String.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC graviton_third_party)
