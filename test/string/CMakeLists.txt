set(SOURCES_STRING_MAIN string_main.cpp)
set(SOURCES_STRING_TEST ${SOURCES_STRING_MAIN} string_test.cpp)

add_executable(test.string.string_test ${SOURCES_STRING_TEST})
target_link_libraries(test.string.string_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.string.string_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_test(test.string.string_test test.string.string_test)
