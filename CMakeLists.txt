cmake_minimum_required(VERSION 3.10)
project(dfsan_test)

SET(CMAKE_CXX_COMPILER clang-9)
set(CMAKE_CXX_STANDARD 11)

add_executable(dfsan_test main.cpp)
set_target_properties(dfsan_test PROPERTIES
        COMPILE_FLAGS "-fsanitize=dataflow -g"
        )
set_target_properties(dfsan_test PROPERTIES
        LINK_FLAGS "-fsanitize=dataflow"
        )