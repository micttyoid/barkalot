message(STATUS "Configuring deque tests")

add_executable(test_node
    test_Node.cpp
)

target_link_libraries(test_node
    PRIVATE
        data_structure_node
        gtest
        gtest_main
)

target_include_directories(test_node
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
)

message(STATUS "Deque test executable will be built at: ${CMAKE_CURRENT_BINARY_DIR}/test_node")

add_test(
    NAME NodeTests
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_node
)
