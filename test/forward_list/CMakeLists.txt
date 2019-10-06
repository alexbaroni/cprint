set(SOURCES_FORWARD_LIST_MAIN forward_list_main.cpp)
set(SOURCES_FORWARD_LIST_TEST ${SOURCES_FORWARD_LIST_MAIN} forward_list_test.cpp)
set(SOURCES_FORWARD_LIST_ALL_TEST ${SOURCES_FORWARD_LIST_MAIN} forward_list_test.cpp)

add_executable(test.forward_list.forward_list_test ${SOURCES_FORWARD_LIST_TEST})
target_link_libraries(test.forward_list.forward_list_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.forward_list.forward_list_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.forward_list.all_test ${SOURCES_FORWARD_LIST_ALL_TEST})
target_link_libraries(test.forward_list.all_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.forward_list.all_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_test(test.forward_list.forward_list_test test.forward_list.forward_list_test)
add_test(test.forward_list.all_test test.forward_list.all_test)
