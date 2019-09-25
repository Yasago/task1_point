include_directories(../src)

include_directories(.)

add_executable(tests
    # point tests
    point_test.cpp
    point_array_test.cpp
    # point sources    
    ../src/xipoint.cpp
    ../src/xipoint.h
    # gtest sources
    gtest/gtest-all.cc
    gtest/gtest_main.cc
)
set(GCC_COVERAGE_COMPILE_FLAGS "-pthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
SET(CMAKE_CXX_FLAGS -pthread)