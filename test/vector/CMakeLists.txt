set(SOURCES_VECTOR_MAIN vector_main.cpp)
set(SOURCES_VECTOR_TEST ${SOURCES_VECTOR_MAIN} vector_test.cpp)
set(SOURCES_VECTOR_VECTOR_TEST ${SOURCES_VECTOR_MAIN} vector_vector_test.cpp)
set(SOURCES_ALL_TEST ${SOURCES_VECTOR_MAIN} vector_test.cpp vector_vector_test.cpp)

add_executable(test.vector.vector_test ${SOURCES_VECTOR_TEST})
target_link_libraries(test.vector.vector_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.vector.vector_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.vector.vector_vector_test ${SOURCES_VECTOR_VECTOR_TEST})
target_link_libraries(test.vector.vector_vector_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.vector.vector_vector_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_executable(test.vector.all_test ${SOURCES_ALL_TEST})
target_link_libraries(test.vector.all_test INTERFACE cprint INTERFACE catch2)
target_include_directories(test.vector.all_test PRIVATE ${CPRINT_INCLUDE_PATH} ${CMCSTL2_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

add_test(test.vector.vector_test test.vector.vector_test)
add_test(test.vector.vector_vector_test test.vector.vector_vector_test)
add_test(test.vector.all_test test.vector.all_test)