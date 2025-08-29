cmake_minimum_required(VERSION 3.16)

project(graviton_third_party)

add_library(${PROJECT_NAME} STATIC
    glad/src/glad.c
)

# glad
target_include_directories(${PROJECT_NAME} PUBLIC glad/include)
target_include_directories(${PROJECT_NAME} PUBLIC glad/include)

# glfw
add_subdirectory(glfw)
target_include_directories(${PROJECT_NAME} PUBLIC glfw/include)
target_include_directories(${PROJECT_NAME} PUBLIC glfw/deps)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)

# glm
add_subdirectory(glm)
target_include_directories(${PROJECT_NAME} PUBLIC glm)

# tinyobjloader
add_subdirectory(tinyobjloader)
target_include_directories(${PROJECT_NAME} PUBLIC tinyobjloader)