add_executable(vector_tests tests/test_vector.cpp)
target_include_directories(vector_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(vector_tests PRIVATE Catch2::Catch2WithMain)
add_test(NAME vector_tests COMMAND vector_tests)
