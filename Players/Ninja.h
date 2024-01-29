#include <utility>

//
// Created by eitan on 1/29/2024.
//

#ifndef NINJA_H
#define NINJA_H

class Ninja : public Player {

public:
    explicit Ninja(std::string name);

    void updateCoins(int amount) override {
        coins += amount * 2;
    }
};

Ninja::Ninja(std::string name) : Player(std::move(name)) {}

#endif //NINJA_H
