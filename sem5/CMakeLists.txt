cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(time VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(ENABLE_TESTS "Enable testing" ON)

set(SOURCE_FILES main.cpp Time.cpp)

add_executable(time ${SOURCE_FILES})

if(ENABLE_TESTS)
    set(GTEST_DIR_LIB "${CMAKE_SOURCE_DIR}/googletests/lib")
    set(GTEST_DIR_INCLUDE "${CMAKE_SOURCE_DIR}/googletests/include")

    include_directories(${GTEST_DIR_INCLUDE})
    include_directories(${CMAKE_SOURCE_DIR})
    link_directories(${GTEST_DIR_LIB})

    set(TEST_SOURCES tests/test_time.cpp)
    add_executable(TimeTests ${TEST_SOURCES})

    target_link_libraries(TimeTests gtest gtest_main)
    add_test(NAME TimeTest COMMAND TimeTest)
endif()