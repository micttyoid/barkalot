message(STATUS "Configuring deque implementation")

add_library(data_structure_node
    Node.cpp
)

# Link to the parent interface library
target_link_libraries(data_structure_node
    PUBLIC
        data_structure
)

target_include_directories(data_structure_node
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

message(STATUS "Linked list library: ${CMAKE_CURRENT_BINARY_DIR}/libdata_structure_node.a")
