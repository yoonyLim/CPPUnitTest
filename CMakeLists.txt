cmake_minimum_required(VERSION 3.28)
project(CPPUnitTest)

# Enable Testing
include(CTest)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)

include_directories(src)

# 'lib' is the folder with Google Test sources
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
