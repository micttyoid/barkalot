message(STATUS "Configuring data_structure library")

# Create a library for the data_structure topic
add_library(data_structure INTERFACE)

# Add include directories
target_include_directories(data_structure
    INTERFACE
        ${CMAKE_SOURCE_DIR}/include
)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/node")
    add_subdirectory(node)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/deque")
    add_subdirectory(deque)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/linked_list")
    add_subdirectory(linked_list)
endif()
