cmake_minimum_required(VERSION 3.28.0)

project(LibTest CXX)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE LinkedList)