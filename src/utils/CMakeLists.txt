cmake_minimum_required(VERSION 3.10)

project(graviton_utils)

file(GLOB SOURCES *.cpp)

add_library(
	${PROJECT_NAME}
	STATIC
	${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE graviton_headers)
target_link_libraries(${PROJECT_NAME} PRIVATE graviton_third_party)