# Create test executable
add_executable(test_SinglyLinkedList test_SinglyLinkedList.cpp)

# Then in your test CMakeLists.txt:
target_include_directories(test_SinglyLinkedList
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

# Link with our library and Catch2
target_link_libraries(test_SinglyLinkedList 
    PRIVATE 
    SinglyLinkedList 
    Catch2::Catch2WithMain
)

# Add test
add_test(
    NAME test_SinglyLinkedList
    COMMAND test_SinglyLinkedList [.] --success
)