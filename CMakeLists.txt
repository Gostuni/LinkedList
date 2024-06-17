cmake_minimum_required(VERSION 3.28.3)

project(LibTest CXX)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE LinkedList)