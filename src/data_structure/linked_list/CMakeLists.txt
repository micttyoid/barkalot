message(STATUS "Configuring linked_list implementation")

add_library(data_structure_linked_list
    DoublyLinkedList.cpp
    SinglyLinkedList.cpp
)

# Link to the parent interface library
target_link_libraries(data_structure_linked_list
    PUBLIC
        data_structure
)

target_include_directories(data_structure_linked_list
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

message(STATUS "Linked list library: ${CMAKE_CURRENT_BINARY_DIR}/libdata_structure_linked_list.a")
