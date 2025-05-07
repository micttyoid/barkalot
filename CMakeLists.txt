cmake_minimum_required(VERSION 3.15)
project(cpp_refresher LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library target (header-only but needs the .cpp for explicit instantiations)
add_library(cpp_refresher
    include/data_structure/linked_list/SinglyLinkedList.h
    src/data_structure/linked_list/SinglyLinkedList.cpp
)

target_include_directories(cpp_refresher
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Testing setup
option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Doxygen
#find_package(Doxygen)
#if(DOXYGEN_FOUND)
#    add_custom_target(docs ALL
#        COMMAND Doxygen::doxygen ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile
#        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs
#    )
#endif()