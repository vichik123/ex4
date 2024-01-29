//
// Created by eitan on 1/13/2024.
//
#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H
#define MAX_HP 100

class Player {

protected:
    std::string name;
    int level;
    int force;
    int healthPoints;
    int coins;

public:

    explicit Player(std::string  name);

    /**
     * Update the number of coins the player has.
     *
     * @param amount is how much to change.
     *          This can be positive or negative.
     */
    virtual void updateCoins(int amount);

    /**
     * Update the health points of the player.
     *
     * @param amount is how many health points are given
     *              or lost (positive or negative respectively).
     */
    virtual void updateHealthPoints(int amount);

    /**
     * Gets the total attack power, defined as force + level.
     *
     * @return the total attack power.
     */
    virtual int getAttackPower();

    friend std::ostream& operator<<(std::ostream& os, Player const& player) {
        return os << "I'm a friend of the class, msg=" << player.name;
    }
};

#endif //PLAYER_H
