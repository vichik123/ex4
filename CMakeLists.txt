cmake_minimum_required(VERSION 3.26)
project(ex4)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors -Werror -DNDEBUG")

add_executable(ex4
        Mtmchkin.cpp Mtmchkin.h
        Players/Player.h
        Players/Player.cpp
        Players/Ninja.h
        Players/Healer.h
        Players/Warrior.h
        Cards/BattleCard.h
        Cards/Gremlin.h
        Cards/Witch.h
        Cards/Dragon.h
        Cards/Treasure.h
        Cards/Well.h
        Cards/Barfight.h
        Cards/Mana.h
        Cards/Card.h
        Cards/Merchant.h
        Cards/BattleCard.cpp
        Cards/Card.cpp
        Exception.h
        utilities.h
        utilities.cpp
        Cards/Barfight.cpp
        Cards/Treasure.cpp
        Cards/Merchant.cpp
        Cards/Well.cpp
        Cards/Mana.cpp
        Cards/Gremlin.cpp
        Cards/Dragon.cpp
        Cards/Witch.cpp
        Players/Ninja.cpp
        Players/Healer.cpp
        Players/Warrior.cpp
        test.cpp
)