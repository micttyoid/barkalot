message(STATUS "Configuring data_structure tests")

# Add subdirectories
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/linked_list")
    add_subdirectory(linked_list)
endif()
