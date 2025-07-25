cmake_minimum_required(VERSION 3.20)

project(graviton LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Collect source files
file(GLOB_RECURSE SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# Create library target
add_library(graviton STATIC ${SOURCE_FILES})

# Set public include directories for the library
target_include_directories(graviton PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Example executable using the library
add_executable(graviton_example ${PROJECT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(graviton_example PRIVATE graviton)
