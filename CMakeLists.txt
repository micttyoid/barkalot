cmake_minimum_required(VERSION 3.15)
project(foo_lib VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Modern FetchContent approach for Catch2
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.2
  FIND_PACKAGE_ARGS NAMES Catch2
)

# This will use FetchContent if not found system-wide
FetchContent_MakeAvailable(Catch2)

# Library target
add_library(foo_lib 
    src/multiplication.cpp
    include/foo_lib/addition.h
    include/foo_lib/multiplication.h
)

target_include_directories(foo_lib PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

enable_testing()
add_subdirectory(tests)
add_subdirectory(examples)

# Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
    add_custom_target(docs ALL
        COMMAND Doxygen::doxygen ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs
    )
endif()