cmake_minimum_required(VERSION 3.10)
project(tkchess)

enable_testing()
set(CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(test)
