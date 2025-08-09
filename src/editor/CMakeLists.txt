cmake_minimum_required(VERSION 3.16)

project(graviton_editor)

add_executable(${PROJECT_NAME}
    Main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE graviton_core)
