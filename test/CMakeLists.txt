cmake_minimum_required(VERSION 3.12)
project(cprint_test)
set(CMAKE_CXX_STANDARD 20)

#configure directories
set (CATCH_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/catch2")

#include custom cmake function
include("${CATCH_INCLUDE_PATH}/ParseAndAddCatchTests.cmake")

add_library(catch2 INTERFACE)
target_sources(catch2 INTERFACE ${CATCH_INCLUDE_PATH}/catch.hpp)
target_include_directories(catch2 INTERFACE ${CATCH_INCLUDE_PATH})

#set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

enable_testing()
add_subdirectory(array)
add_subdirectory(vector)
add_subdirectory(string)
add_subdirectory(span)
add_subdirectory(pair)
add_subdirectory(deque)
add_subdirectory(forward_list)
add_subdirectory(list)
add_subdirectory(set)
add_subdirectory(map)

#ParseAndAddCatchTests(cprint_test)