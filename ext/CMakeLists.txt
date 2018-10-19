cmake_minimum_required(VERSION 3.12)
project(cprint_ext)
set(CMAKE_CXX_STANDARD 17)

set(EXT_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

#cmcstl2
find_path(CMCSTL2_HEADERS_ROOT "concepts.hpp" NO_DEFAULT_PATH  PATHS "${CMAKE_CURRENT_SOURCE_DIR}/cmcstl2/include/stl2")

if((NOT CMCSTL2_HEADERS_ROOT) OR (NOT EXISTS ${CMCSTL2_HEADERS_ROOT}))
  #not found cmcstl2, clone it
  message(STATUS "Unable to find cmcstl2")
  execute_process(COMMAND git submodule update --init -- cmcstl2 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()

#configure directories
set (CMCSTL2_MODULE_PATH "${EXT_MODULE_PATH}/cmcstl2")
set (CMCSTL2_INCLUDE_PATH "${CMCSTL2_MODULE_PATH}/include" PARENT_SCOPE)

add_subdirectory(cmcstl2 EXCLUDE_FROM_ALL)