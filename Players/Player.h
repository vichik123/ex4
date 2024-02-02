//
// Created by eitan on 1/13/2024.
//
#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H
#define MAX_HP 100

#include "../Cards/EnemyCard.h"

class Player {

protected:
    std::string name;
    std::string className;
    int level;
    int force;
    int healthPoints;
    int coins;

public:
    explicit Player(std::string name, std::string className);

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

    std::string getClass();

    const std::string &getName() const;

    int getCoins() const;

    void fight(const EnemyCard& card) {
        if (card.getForce() >= getAttackPower()) {
            updateHealthPoints(-card.getLoss());
        } else {
            updateCoins(card.getLoot());
        }
    }

    friend std::ostream& operator<<(std::ostream& os, Player const& player) {
        return os << player.name;
    }
};

#endif //PLAYER_H
