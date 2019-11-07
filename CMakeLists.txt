### Global info
cmake_minimum_required(VERSION 3.5)
project(PhantomOperaAI)

set(CMAKE_CXX_FLAGS "-Wl,--no-as-needed ${CMAKE_CXX_FLAGS} -std=c++11")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

file(
        GLOB_RECURSE
        SRCS_ALL
        includes/*
        srcs/BoardScorer.cpp
        srcs/Character.cpp
        srcs/CharacterMove.cpp
        srcs/Color.cpp
        srcs/FantomAI.cpp
        srcs/GameData.cpp
        srcs/GameState.cpp
        srcs/InspectorAI.cpp
        srcs/KeyEvaluator.cpp
        srcs/Logger.cpp
        srcs/Net.cpp
        srcs/Question.cpp
        srcs/Tile.cpp
        srcs/TreeHandler.cpp
)

file(
        GLOB_RECURSE
        SRCS_TEST
        srcs/main_test.cpp
)

file(
        GLOB_RECURSE
        SRCS_MAIN
        srcs/main.cpp
)

include_directories(includes/)

add_executable(
        PhantomOperaAI
        ${SRCS_ALL}
        ${SRCS_MAIN}
)

add_executable(
        Test
        ${SRCS_ALL}
        ${SRCS_TEST}
)
