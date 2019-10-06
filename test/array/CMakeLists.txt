set(SOURCES_ARRAY_MAIN array_main.cpp)
set(SOURCES_ARRAY_TEST ${SOURCES_ARRAY_MAIN} array_test.cpp)
set(SOURCES_ARRAY_FMT_TEST ${SOURCES_ARRAY_MAIN} array_fmt_test.cpp)
set(SOURCES_CARRAY_TEST ${SOURCES_ARRAY_MAIN} carray_test.cpp)
set(SOURCES_VALARRAY_TEST ${SOURCES_ARRAY_MAIN} valarray_test.cpp)
set(SOURCES_ARRAY_ALL_TEST ${SOURCES_ARRAY_MAIN} array_test.cpp array_fmt_test.cpp valarray_test.cpp carray_test.cpp)

add_executable(test.array.array_test ${SOURCES_ARRAY_TEST})
target_link_libraries(test.array.array_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.array.array_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.array.array_fmt_test ${SOURCES_ARRAY_FMT_TEST})
target_link_libraries(test.array.array_fmt_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.array.array_fmt_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.array.carray_test ${SOURCES_CARRAY_TEST})
target_link_libraries(test.array.carray_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.array.carray_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.array.valarray_test ${SOURCES_VALARRAY_TEST})
target_link_libraries(test.array.valarray_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.array.valarray_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.array.all_test ${SOURCES_ARRAY_ALL_TEST})
target_link_libraries(test.array.all_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.array.all_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_test(test.array.array_test test.array.array_test)
add_test(test.array.array_fmt_test test.array.array_fmt_test)
add_test(test.array.carray_test test.array.carray_test)
add_test(test.array.valarray_test test.array.valarray_test)
add_test(test.array.all_test test.array.all_test)
