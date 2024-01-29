#include <utility>

//
// Created by eitan on 1/29/2024.
//

#ifndef HEALER_H
#define HEALER_H

class Healer : public Player {

public:
    explicit Healer(std::string name);

    void updateHealthPoints(int amount) override {
        if (amount > 0) {
            healthPoints += amount * 2;
        } else {
            healthPoints += amount;
        }
    }

};

Healer::Healer(std::string name) : Player(std::move(name)) {}

#endif //HEALER_H
