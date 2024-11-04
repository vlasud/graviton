cmake_minimum_required(VERSION 3.8)

project(graviton CXX C)

set(CMAKE_CXX_STANDARD 20)

file(GLOB GRAVITON_SRC ${PROJECT_SOURCE_DIR}/src/*/*.cpp)

add_library(${PROJECT_NAME} ${GRAVITON_SRC})

if (WIN32)
    target_link_options(${PROJECT_NAME} PUBLIC /SUBSYSTEM:WINDOWS)
endif()

# graviton include dirs
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

# glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")
set(GLAD_GL "")

add_subdirectory(third_party/glfw)
target_include_directories(${PROJECT_NAME} PUBLIC
    third_party/glfw/include
    third_party/glfw/deps
)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
