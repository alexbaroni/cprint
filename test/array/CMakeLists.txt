set(SOURCES_ARRAY_MAIN array_main.cpp)
set(SOURCES_ARRAY_TEST ${SOURCES_ARRAY_MAIN} array_test.cpp)

add_executable(test.array.array_test ${SOURCES_ARRAY_TEST})
target_link_libraries(test.array.array_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.array.array_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_test(test.array.array_test test.array.array_test)
