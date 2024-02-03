#include <utility>

#ifndef NINJA_H
#define NINJA_H

#include "Player.h"

class Ninja : public Player {

public:
    explicit Ninja(std::string name);

    void updateCoins(int amount) override {
        coins += amount * 2;
    }
};

#endif //NINJA_H
