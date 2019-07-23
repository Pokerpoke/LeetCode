project(LeetCode)

cmake_minimum_required(VERSION 3.10)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
enable_testing()
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${GTEST_INCLUDE_DIR})

add_subdirectory(include)

add_subdirectory(src)