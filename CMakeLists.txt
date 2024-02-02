cmake_minimum_required(VERSION 3.26)
project(ex4)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors -Werror -DNDEBUG")

add_executable(ex4 test.cpp
        Mtmchkin.cpp Mtmchkin.h
        Players/Player.h
        Players/Player.cpp
        Players/Ninja.h
        Players/Healer.h
        Players/Warrior.h
        Cards/EnemyCard.h
        Cards/Gremlin.h
        Cards/Witch.h
        Cards/Dragon.h
        Cards/Treasure.h
        Cards/Well.h
        Cards/Barfight.h
        Cards/Mana.h
        Cards/BattleCard.h
        Cards/Merchant.h
        Cards/EnemyCard.cpp
        Cards/BattleCard.cpp
        utilities.cpp)