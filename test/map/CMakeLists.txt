set(SOURCES_MAP_MAIN map_main.cpp)
set(SOURCES_MAP_TEST ${SOURCES_MAP_MAIN} map_test.cpp)
set(SOURCES_MULTIMAP_TEST ${SOURCES_MAP_MAIN} multimap_test.cpp)
set(SOURCES_UNORDERED_MAP_TEST ${SOURCES_MAP_MAIN} unordered_map_test.cpp)
set(SOURCES_MAP_ALL_TEST ${SOURCES_MAP_MAIN} map_test.cpp multimap_test.cpp unordered_map_test.cpp)

add_executable(test.map.map_test ${SOURCES_MAP_TEST})
target_link_libraries(test.map.map_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.map.map_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.map.multimap_test ${SOURCES_MULTIMAP_TEST})
target_link_libraries(test.map.multimap_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.map.multimap_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.map.unordered_map_test ${SOURCES_UNORDERED_MAP_TEST})
target_link_libraries(test.map.unordered_map_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.map.unordered_map_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.map.all_test ${SOURCES_MAP_ALL_TEST})
target_link_libraries(test.map.all_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.map.all_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_test(test.map.map_test test.map.map_test)
add_test(test.map.multimap_test test.map.multimap_test)
add_test(test.map.unordered_map_test test.map.unordered_map_test)
add_test(test.map.all_test test.map.all_test)
