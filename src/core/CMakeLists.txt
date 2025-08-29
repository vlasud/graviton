cmake_minimum_required(VERSION 3.16)

project(graviton_core)

add_library(${PROJECT_NAME} STATIC
    Engine.cpp
    Engine.h

    render/Renderer.cpp
    render/RenderQueue.cpp
    render/Mesh.cpp
    render/Camera.cpp

    util/String.h
    util/String.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC graviton_third_party)
