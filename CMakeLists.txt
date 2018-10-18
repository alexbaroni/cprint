cmake_minimum_required(VERSION 3.12)

project(cprint)

set(CMAKE_CXX_STANDARD 17)

add_compile_options("-fconcepts;-ftemplate-backtrace-limit=0")
add_compile_options("-Wall;-Wextra;-pedantic-errors;-Werror;-march=native")
add_compile_options("$<$<CONFIG:DEBUG>:-O0;-fno-inline;-g3;-fno-omit-frame-pointer;-fno-stack-protector;-mieee-fp;-Wl,--stack,16777216>")
add_compile_options("$<$<CONFIG:RELEASE>:-O3;-g0;-DNDEBUG;-Wl,--stack,16777216>")
add_compile_options("$<$<CONFIG:RELWITHDEBINFO>:-O2;-g;-DNDEBUG;-Wl,--stack,16777216>")

set(CPRINT_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(cprint INTERFACE)
target_sources(cprint INTERFACE "${CPRINT_INCLUDE_PATH}/cprint/cprint.hpp")
target_include_directories(cprint INTERFACE ${CPRINT_INCLUDE_PATH})
