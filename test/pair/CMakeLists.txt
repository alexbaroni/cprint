set(SOURCES_PAIR_MAIN pair_main.cpp)
set(SOURCES_PAIR_TEST ${SOURCES_PAIR_MAIN} pair_test.cpp)
set(SOURCES_PAIR_COMPLEX_TEST ${SOURCES_PAIR_MAIN} pair_complex_test.cpp)
set(SOURCES_PAIR_ALL_TEST ${SOURCES_PAIR_MAIN} pair_test.cpp pair_complex_test.cpp)

add_executable(test.pair.pair_test ${SOURCES_PAIR_TEST})
target_link_libraries(test.pair.pair_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.pair.pair_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.pair.pair_complex_test ${SOURCES_PAIR_COMPLEX_TEST})
target_link_libraries(test.pair.pair_complex_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.pair.pair_complex_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.pair.all_test ${SOURCES_PAIR_ALL_TEST})
target_link_libraries(test.pair.all_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.pair.all_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_test(test.pair.pair_test test.pair.pair_test)
add_test(test.pair.pair_complex_test test.pair.pair_complex_test)
add_test(test.pair.all_test test.pair.all_test)
