set(SOURCES_SET_MAIN set_main.cpp)
set(SOURCES_SET_TEST ${SOURCES_SET_MAIN} set_test.cpp)
set(SOURCES_MULTISET_TEST ${SOURCES_SET_MAIN} multiset_test.cpp)
set(SOURCES_UNORDERED_SET_TEST ${SOURCES_SET_MAIN} unordered_set_test.cpp)
set(SOURCES_SET_ALL_TEST ${SOURCES_SET_MAIN} set_test.cpp multiset_test.cpp unordered_set_test.cpp)

add_executable(test.set.set_test ${SOURCES_SET_TEST})
target_link_libraries(test.set.set_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.set.set_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.set.multiset_test ${SOURCES_MULTISET_TEST})
target_link_libraries(test.set.multiset_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.set.multiset_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.set.unordered_set_test ${SOURCES_UNORDERED_SET_TEST})
target_link_libraries(test.set.unordered_set_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.set.unordered_set_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.set.all_test ${SOURCES_SET_ALL_TEST})
target_link_libraries(test.set.all_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.set.all_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_test(test.set.set_test test.set.set_test)
add_test(test.set.multiset_test test.set.multiset_test)
add_test(test.set.unordered_set_test test.set.unordered_set_test)
add_test(test.set.all_test test.set.all_test)
