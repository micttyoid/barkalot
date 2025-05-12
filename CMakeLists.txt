cmake_minimum_required(VERSION 3.15)
project(barkalot LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTS "Build unit tests" ON)
option(BUILD_EXAMPLES "Build example programs" OFF)

if(BUILD_TESTS)
    # Option 1: Use FindGTest
    set(GTEST_ROOT "/usr/include/gtest")
    find_package(GTest REQUIRED)
    
    # Option 2: Use FetchContent
    #include(FetchContent)
    #FetchContent_Declare(
    #    googletest
    #    GIT_REPOSITORY https://github.com/google/googletest.git
    #    GIT_TAG release-1.12.1
    #)
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    #set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    #FetchContent_MakeAvailable(googletest)

    
    enable_testing()
    include(GoogleTest)
endif()

file(GLOB TOPICS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/include" "include/*")
foreach(TOPIC ${TOPICS})
    message(STATUS "Configuring topic: ${TOPIC}")

    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/${TOPIC}")
        add_subdirectory(src/${TOPIC})
    endif()
    
    if(BUILD_TESTS AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/${TOPIC}")
        message(STATUS "  Enabling tests for ${TOPIC}")
        add_subdirectory(tests/${TOPIC})
    endif()
    
    if(BUILD_EXAMPLES AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/examples/${TOPIC}")
        message(STATUS "  Enabling example for ${TOPIC}")
        add_subdirectory(examples/${TOPIC})
    endif()
endforeach()

if(PROJECT_IS_TOP_LEVEL)
    include(GNUInstallDirs)
    install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endif()
