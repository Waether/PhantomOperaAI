### Global info
cmake_minimum_required(VERSION 3.5)
project(PhantomOperaAI)

set(CMAKE_CXX_FLAGS "-Wl,--no-as-needed ${CMAKE_CXX_FLAGS} -std=c++11")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

file(
        GLOB_RECURSE
        SRCS
        includes/*
        srcs/*
)

include_directories(includes/)

add_executable(
        PhantomOperaAI
        ${SRCS}
)
