cmake_minimum_required(VERSION 3.26)
project(ex4)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors -Werror -DNDEBUG")

add_library(util SHARED utilities.cpp utilities.h)
add_library(mtmchkin SHARED Mtmchkin.cpp Mtmchkin.h Players/Player.h
        Cards/BattleCard.h
        Cards/Gremlin.h
        Cards/Witch.h
        Cards/BattleCard.cpp
        Cards/Dragon.h
        Players/Player.cpp
        Players/Ninja.h
        Players/Healer.h
        Players/Warrior.h
)
add_executable(ex4 test.cpp)
target_link_libraries(ex4 util)
target_link_libraries(ex4 mtmchkin)