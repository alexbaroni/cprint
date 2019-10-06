set(SOURCES_LIST_MAIN list_main.cpp)
set(SOURCES_LIST_TEST ${SOURCES_LIST_MAIN} list_test.cpp)
set(SOURCES_LIST_ALL_TEST ${SOURCES_LIST_MAIN} list_test.cpp)

add_executable(test.list.list_test ${SOURCES_LIST_TEST})
target_link_libraries(test.list.list_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.list.list_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.list.all_test ${SOURCES_LIST_ALL_TEST})
target_link_libraries(test.list.all_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.list.all_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_test(test.list.list_test test.list.list_test)
add_test(test.list.all_test test.list.all_test)
