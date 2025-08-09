cmake_minimum_required(VERSION 3.16)

project(graviton_third_party)

add_library(${PROJECT_NAME} STATIC
    glad/src/glad.c
)

target_include_directories(${PROJECT_NAME} PUBLIC glad/include)

add_subdirectory(glfw)
target_include_directories(${PROJECT_NAME} PUBLIC glfw/include)
target_include_directories(${PROJECT_NAME} PUBLIC glfw/deps)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)