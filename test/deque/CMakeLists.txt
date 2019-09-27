set(SOURCES_DEQUE_MAIN deque_main.cpp)
set(SOURCES_DEQUE_TEST ${SOURCES_DEQUE_MAIN} deque_test.cpp)
set(SOURCES_DEQUE_ALL_TEST ${SOURCES_DEQUE_MAIN} deque_test.cpp)

add_executable(test.deque.deque_test ${SOURCES_DEQUE_TEST})
target_link_libraries(test.deque.deque_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.deque.deque_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.deque.all_test ${SOURCES_DEQUE_ALL_TEST})
target_link_libraries(test.deque.all_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.deque.all_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_test(test.deque.deque_test test.deque.deque_test)
add_test(test.deque.all_test test.deque.all_test)
