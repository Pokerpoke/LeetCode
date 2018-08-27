project(LeetCode)

cmake_minimum_required(VERSION 2.6)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(include)

add_subdirectory(src)