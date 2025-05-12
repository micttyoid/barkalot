message(STATUS "Configuring linked_list tests")

add_executable(test_doubly_linked_list
    test_DoublyLinkedList.cpp
)

target_link_libraries(test_doubly_linked_list
    PRIVATE
        data_structure_linked_list
        gtest
        gtest_main
)

target_include_directories(test_doubly_linked_list
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
)

message(STATUS "DoublyLinkedList test executable will be built at: ${CMAKE_CURRENT_BINARY_DIR}/test_doubly_linked_list")

add_test(
    NAME DoublyLinkedListTests
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_doubly_linked_list
)

add_executable(test_singly_linked_list
    test_SinglyLinkedList.cpp
)

target_link_libraries(test_singly_linked_list
    PRIVATE
        data_structure_linked_list
        gtest
        gtest_main
)

target_include_directories(test_singly_linked_list
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
)

message(STATUS "SinglyLinkedList test executable will be built at: ${CMAKE_CURRENT_BINARY_DIR}/test_singly_linked_list")

add_test(
    NAME SinglyLinkedListTests
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_singly_linked_list
)
