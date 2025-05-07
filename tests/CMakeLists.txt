# Find Catch2
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

# Add test for linked_list/
add_executable(test_linked_list
    data_structure/linked_list/test_SinglyLinkedList.cpp
)

target_link_libraries(test_linked_list
    PRIVATE
    cpp_refresher
    Catch2::Catch2WithMain
)

add_test(
    NAME LinkedLists
    COMMAND test_linked_list
)

# Future test targets can be added here following the same pattern
# add_executable(test_other_structure ...)
# target_link_libraries(test_other_structure ...)
# add_test(...)