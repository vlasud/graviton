cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

# Engine headers
project(graviton_headers)
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include)

# Other
add_subdirectory(third_party)
add_subdirectory(src/utils)
add_subdirectory(src/render)
add_subdirectory(src/core)


# Graviton lib
project(graviton)
add_library(${PROJECT_NAME} INTERFACE)

target_link_libraries(${PROJECT_NAME} INTERFACE graviton_headers)
target_link_libraries(${PROJECT_NAME} INTERFACE graviton_core)
target_link_libraries(${PROJECT_NAME} INTERFACE graviton_render)
target_link_libraries(${PROJECT_NAME} INTERFACE graviton_utils)
target_link_libraries(${PROJECT_NAME} INTERFACE graviton_third_party)
