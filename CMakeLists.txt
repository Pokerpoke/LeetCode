project(LeetCode)

# CMake version >= 3.10 due to gtest_discover_tests()
# See https://cmake.org/cmake/help/git-stage/module/GoogleTest.html
cmake_minimum_required(VERSION 3.10)

enable_testing()
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${GTEST_INCLUDE_DIR})

add_subdirectory(include)

add_subdirectory(test)
add_subdirectory(src)