cmake_minimum_required(VERSION 3.10)

project(graviton_third_party)

add_library(${PROJECT_NAME} STATIC
	${PROJECT_SOURCE_DIR}/glfw/deps/glad_gl.c
)

# GLFW
add_subdirectory(glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_include_directories(${PROJECT_NAME} PUBLIC glfw/include)
target_include_directories(${PROJECT_NAME} PUBLIC glfw/deps)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL::GL)

# GLM
add_subdirectory(glm)
target_include_directories(${PROJECT_NAME} PUBLIC glm)

# EASTL
add_subdirectory(EASTL)
target_link_libraries(${PROJECT_NAME} PUBLIC EASTL)
