//
// Created by eitan on 1/29/2024.
//

#ifndef WARRIOR_H
#define WARRIOR_H

#include <utility>

#include "Player.h"

class Warrior : public Player {

public:
    explicit Warrior(std::string name);

    int getAttackPower() override {
        return 2 * force + level;
    }
};

Warrior::Warrior(std::string name) : Player(std::move(name)) {}

#endif //WARRIOR_H
