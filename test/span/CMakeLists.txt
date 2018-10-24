add_executable(test.span.span_test span_test.cpp)
target_link_libraries(test.span.span_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.span.span_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_test(test.span.span_test test.span.span_test)

