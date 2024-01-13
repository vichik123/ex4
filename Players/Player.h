//
// Created by eitan on 1/13/2024.
//
#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H
#define MAX_HP 100

class Player {

public:
    enum Class {
        NINJA,
        HEALER,
        WARRIOR
    };

private:
    Class playerClass;
    std::string name;
    int level;
    int force;
    int healthPoints;
    int coins;

public:
    /**
     * Update the number of coins the player has.
     *
     * @param amount is how much to change.
     *          This can be positive or negative.
     */
    void updateCoins(int amount);

    /**
     * Update the health points of the player.
     *
     * @param amount is how many health points are given
     *              or lost (positive or negative respectively).
     */
    void updateHealthPoints(int amount);
};

#endif //PLAYER_H
