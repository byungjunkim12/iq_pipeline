cmake_minimum_required(VERSION 3.15)
cmake_minimum_required(VERSION 3.15)
project(iq_pipeline)
set(CMAKE_CXX_STANDARD 17)

add_executable(iq_pipeline
    src/main.cpp
    src/producer.cpp
    src/consumer.cpp
)

target_include_directories(iq_pipeline PRIVATE include)

# gtest
find_package(GTest REQUIRED)

add_executable(iq_pipeline_test
    tests/queue_test.cpp)
target_include_directories(iq_pipeline_test PRIVATE include)
target_link_libraries(iq_pipeline_test GTest::gtest GTest::gtest_main)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
