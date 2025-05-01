find_package(Catch2 REQUIRED)

add_executable(test_foo_lib
    test_addition.cpp
    test_multiplication.cpp
)

target_link_libraries(test_foo_lib
    PRIVATE foo_lib Catch2::Catch2WithMain
)

add_test(NAME foo_lib_tests COMMAND test_foo_lib)