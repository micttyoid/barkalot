message(STATUS "Configuring data_structure tests")

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/node")
    add_subdirectory(node)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/linked_list")
    add_subdirectory(linked_list)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/deque")
    add_subdirectory(deque)
endif()
