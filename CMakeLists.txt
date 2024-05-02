cmake_minimum_required(VERSION 3.14)
project("FooBar-Project") # 

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

enable_testing()

set(SOURCE_FILES
        src/InputManagement.cpp
        src/BloomFilter.cpp
        src/HashCode.cpp
        src/CheckAddress.cpp
        src/AddAddress.cpp
        src/main.cpp
        src/App.cpp # this is where the code we want to test
)

set(TEST_FILES
        tests/test_main.cpp # this is the main for tests
        tests/bloom_filter_test.cpp
        #tests/hash_code_test.cpp # this file contain the tests


)
add_executable(FoobarTests ${TEST_FILES})

# Link Google Test to the test executable
target_link_libraries(FoobarTests PRIVATE gtest gtest_main)

# Include the source directory for tests
target_include_directories(FoobarTests PRIVATE src)
include(GoogleTest)
add_test(NAME FoobarTests COMMAND FoobarTests)