cmake_minimum_required(VERSION 3.15)
project(iq_pipeline)

set(CMAKE_CXX_STANDARD 17)

add_executable(iq_pipeline
    src/main.cpp
    src/producer.cpp
    src/consumer.cpp
)

target_include_directories(iq_pipeline PRIVATE include)

