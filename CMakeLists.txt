### Global info
cmake_minimum_required(VERSION 3.5)
project(PhantomOperaAI)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

set(
        SRCS_ALL
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
        srcs/TreeHandler.cpp
)

include_directories(includes/)

add_executable(
        PhantomOperaAI
        ${SRCS_ALL}
        srcs/main.cpp
)
